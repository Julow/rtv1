/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 23:49:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
#include "ft/math_mat3.h"
#include "ft/math_vec3.h"
#include "ft/math_vec4.h"

#include "internal.h"

#include <math.h>

struct s_ray_stats	g_ray_stats = {0, 0, 0, 0, 0};

t_vec4			texture_nearest(t_img const *texture, t_vec2 uv)
{
	uv = VEC2(fmod(ABS(uv.x), 1.f) * texture->width,
		fmod(ABS(uv.y), 1.f) * texture->height);
	return (COLOR_32TOF(IMG_PIXEL(*texture, (uint32_t)uv.x, (uint32_t)uv.y)));
}

#define TEXTURE_F(T,P,X,Y)	(COLOR_32TOF(IMG_PIXEL(*(T), (P)[X].x, (P)[Y].y)))

t_vec4			texture_bilinear(t_img const *texture, t_vec2 uv)
{
	t_vec2i			p[2];

	uv = VEC2(fmod(ABS(uv.x), 1.f) * texture->width - 0.5f,
		fmod(ABS(uv.y), 1.f) * texture->height - 0.5f);
	p[0] = VEC2I(uv.x, uv.y);
	uv = VEC2(uv.x - p[0].x, uv.y - p[0].y);
	if (p[0].x < 0)
		p[0].x = texture->width - 1;
	if (p[0].y < 0)
		p[0].y = texture->height - 1;
	p[1] = VEC2I((p[0].x + 1) % texture->width, (p[0].y + 1) % texture->height);
	return (VEC4_ADD(VEC4_MUL1(VEC4_ADD(
			VEC4_MUL1(TEXTURE_F(texture, p, 0, 0), 1.f - uv.x),
			VEC4_MUL1(TEXTURE_F(texture, p, 1, 0), uv.x)), 1.f - uv.y),
		VEC4_MUL1(VEC4_ADD(VEC4_MUL1(TEXTURE_F(texture, p, 0, 1), 1.f - uv.x),
			VEC4_MUL1(TEXTURE_F(texture, p, 1, 1), uv.x)), uv.y)));
}

/*
** light through objects:
**  light_rgb =
**  	LERP(obj_rgb * (1 - obj_a) * light_rgb * obj_a, light_rgb, obj_a)
** -
** TODO: attenuation (w)
*/

static t_vec4	light_color(t_scene const *scene, t_light const *light,
					t_vec3 const *intersect_pos, t_vec3 const *light_dir)
{
	t_vertex		ray;
	t_obj const		*obj;
	t_vec3			color;
	t_intersect		intersect;
	t_vec4			obj_color;

	g_ray_stats.light_ray++;
	ray = VERTEX(light->pos, VEC3_SUB(VEC3_0(), *light_dir));
	color = light->color;
	while ((obj = nearest_intersect(&intersect, scene, ray)) != NULL)
	{
		if (ft_vec3dist2(*intersect_pos, intersect.pos) <= RAY_ERROR)
			break ;
		obj_color = texture_bilinear(obj->material.texture, intersect.tex);
		color = VEC3_MUL(color, VEC3_SUB1(
				VEC3_MUL1(obj_color, obj_color.w * (1 - obj_color.w)),
				obj_color.w - 1));
		ray.pos = intersect.pos;
	}
	return (VEC4_3(color, light->brightness));
}

/*
** light:
**  light_dir = norm(light_pos - intrsc_pos)
**  b = dot(intrsc_norm, light_dir) * light_brightness
** attenuation:
**  b *= att = 1.f - (dist^2 / max_dist^2)
** spot light:
**  b *= (dot(light_dir, -spot_dir) < spot_cutoff)
** sum:
**  light_sum += light_rgb * b
** -
** TODO: attenuation factor in material (remove t_light.max_dist)
** TODO: check specular
*/

t_vec4			ray_to_light(t_scene const *scene, t_material const *mat,
					t_vertex const *ray, t_intersect const *intersect)
{
	uint32_t		i;
	t_light const	*light;
	t_vec3			light_sum;
	float			specular_sum;
	t_vec4			tmp_color;
	float			b;
	float			tmp;
	t_vec3			light_dir;

	i = 0;
	light_sum = VEC3_1(mat->ambient);
	specular_sum = 0.f;
	while (i < scene->lights.length)
	{
		light = VECTOR_GET(scene->lights, i++);
		light_dir = VEC3_SUB(light->pos, intersect->pos);
		tmp = ft_vec3length(light_dir);
		light_dir = VEC3_DIV1(light_dir, tmp);
		tmp_color = light_color(scene, light, &intersect->pos, &light_dir);
		if ((tmp = 1.f - (tmp * tmp) / (light->max_dist * light->max_dist)) <= 0.f
			|| (b = tmp_color.w * VEC3_DOT(intersect->norm, light_dir) * (tmp * tmp)) <= 0.f
			|| VEC3_DOT(light_dir, VEC3_SUB(VEC3_0(), light->dir)) < light->cutoff)
			continue ;
		tmp = ft_vec3dot(intersect->norm, ft_vec3norm(VEC3_SUB(light_dir, ray->dir)));
		specular_sum += (tmp <= 0.f) ? 0.f : powf(tmp, mat->specular_exp) * b;
		light_sum = VEC3_ADD(light_sum, VEC3_MUL1(tmp_color, b));
	}
	tmp_color = (mat->specular_map != NULL) ?
		texture_bilinear(mat->specular_map, intersect->tex) : VEC4_1(1.f);
	light_sum = VEC3_MUL(light_sum, VEC3_ADD1(VEC3_MUL1(tmp_color, specular_sum), 1.f));
	tmp_color = texture_bilinear(mat->texture, intersect->tex);
	light_sum = VEC3_MIN(VEC3_MUL(tmp_color, light_sum), VEC3_1(1.f));
	return (VEC4(light_sum.x, light_sum.y, light_sum.z, tmp_color.w));
}

/*
** TODO: pass from/to materials
*/
static bool		refracted_ray(t_vertex const *ray, t_material const *material,
					t_intersect const *intersect, t_vec3 *dst)
{
	float			index = 1.f / material->refract_index;
	float			tmp;
	float			cos_t;

	if (index <= 0.f)
	{
		*dst = ray->dir;
		return (true);
	}
	cos_t = VEC3_DOT(ray->dir, intersect->norm);
	tmp = index * index * (1.f - (cos_t * cos_t));
	if (tmp > 1.f)
		return (false);
	tmp = index * cos_t - sqrtf(1.f - tmp);
	*dst = ft_vec3norm(VEC3_ADD(VEC3_MUL1(ray->dir, index),
		VEC3_MUL1(intersect->norm, tmp)));
	return (true);
}

static void		trace_reflection(t_scene const *scene, t_vertex const *ray,
					t_material const *material, t_intersect const *intersect,
					uint32_t max_depth, t_vec3 *color)
{
	t_vertex		tmp;

	if (material->reflection < 0.001f)
		return ;
	tmp.pos = intersect->pos;
	tmp.dir = ft_vec3norm(VEC3_ADD(ray->dir, VEC3_MUL1(intersect->norm,
		-2.f * VEC3_DOT(intersect->norm, ray->dir))));
	*color = ft_vec3mix(ray_trace(scene, &tmp, max_depth),
		*color, material->reflection);
}

static void		trace_refraction(t_scene const *scene, t_vertex const *ray,
					t_material const *material, t_intersect const *intersect,
					uint32_t max_depth, t_vec4 *color)
{
	t_vertex		tmp;

	if (color->w < 0.999f && refracted_ray(ray, material, intersect, &tmp.dir))
	{
		tmp.pos = intersect->pos;
		*(t_vec3*)color = ft_vec3mix(*(t_vec3*)color,
			ray_trace(scene, &tmp, max_depth), color->w);
	}
	color->w = 1.f;
}

static void		apply_normal_map(t_obj const *obj, t_intersect *intersect)
{
	t_vec4			map_normal;
	t_mat3			tbn;
	t_vec3			up;

	up = VEC3_UP();
	ft_mat4apply_vec3(&obj->m_inv, &up, 0.f);
	tbn.x = ft_vec3norm(VEC3_CROSS(intersect->norm, up));
	tbn.y = VEC3_CROSS(tbn.x, intersect->norm);
	tbn.z = intersect->norm;
	ft_mat3transpose(&tbn);
	map_normal = texture_bilinear(obj->material.normal_map, intersect->tex);
	intersect->norm = ft_vec3norm(VEC3_SUB1(VEC3_MUL1(map_normal, 2.f), 1.f));
	ft_mat3apply(&tbn, &intersect->norm);
}

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray,
					uint32_t max_depth)
{
	t_intersect			intersect;
	t_obj const			*obj;
	t_vec4				color;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (g_ray_stats.sky_ray++, scene->sky_color);
	g_ray_stats.render_ray++;
	intersect.norm = ft_vec3norm(intersect.norm);
	if (obj->material.normal_map != NULL)
		apply_normal_map(obj, &intersect);
	color = ray_to_light(scene, &obj->material, ray, &intersect);
	if (max_depth-- > 0)
	{
		trace_refraction(scene, ray, &obj->material, &intersect,
			max_depth, &color);
		trace_reflection(scene, ray, &obj->material, &intersect,
			max_depth, (t_vec3*)&color);
	}
	return (*(t_vec3*)&color);
}
