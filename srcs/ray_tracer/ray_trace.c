/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/14 22:44:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"
#include "internal.h"

#include <math.h>

static float	nearest_dist2(t_scene const *scene, t_vertex const *ray)
{
	t_intersect		intersect;

	if (nearest_intersect(&intersect, scene, *ray) == NULL)
		return (HUGE_VAL);
	return (ft_vec3dist2(ray->pos, intersect.pos));
}

t_vec3			texture_nearest(t_img const *texture, t_vec2 uv)
{
	uv = VEC2(fmod(ABS(uv.x), 1.f) * texture->width,
		fmod(ABS(uv.y), 1.f) * texture->height);
	return (color_24tof(IMG_PIXEL(*texture, (uint32_t)uv.x, (uint32_t)uv.y)));
}

#define TEXTURE_F(T,P,X,Y)	(COLOR_24TOF(IMG_PIXEL(*(T), (P)[X].x, (P)[Y].y)))

t_vec3			texture_bilinear(t_img const *texture, t_vec2 uv)
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
	return (VEC3_ADD(VEC3_MUL1(VEC3_ADD(
			VEC3_MUL1(TEXTURE_F(texture, p, 0, 0), 1.f - uv.x),
			VEC3_MUL1(TEXTURE_F(texture, p, 1, 0), uv.x)), 1.f - uv.y),
		VEC3_MUL1(VEC3_ADD(VEC3_MUL1(TEXTURE_F(texture, p, 0, 1), 1.f - uv.x),
			VEC3_MUL1(TEXTURE_F(texture, p, 1, 1), uv.x)), uv.y)));
}

t_vec3			ray_to_light(t_scene const *scene, t_material const *mat,
					t_vertex const *ray, t_intersect const *intersect)
{
	uint32_t		i;
	t_light const	*light;
	t_vec3			light_sum;
	float			specular_sum;
	t_vec3			tmp_color;
	float			tmp;
	float			tmp2;
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
		if ((tmp * tmp) > nearest_dist2(scene, &VERTEX(intersect->pos, light_dir))
			|| (tmp2 = 1.f - tmp / light->att_dist) <= 0.f
			|| (tmp = VEC3_DOT(intersect->norm, light_dir)) < 0.f)
			continue ;
		tmp = light->brightness * tmp * powf(tmp2, light->att_exp);
		tmp2 = ft_vec3dot(intersect->norm, ft_vec3norm(VEC3_SUB(light_dir, ray->dir)));
		specular_sum += (tmp2 <= 0.f) ? 0.f : powf(tmp2, mat->specular_exp) * tmp;
		light_sum = VEC3_ADD(light_sum, VEC3_MUL1(light->color, tmp));
	}
	tmp_color = (mat->specular_map != NULL) ?
		texture_bilinear(mat->specular_map, intersect->tex) : VEC3_1(1.f);
	light_sum = VEC3_MUL(light_sum, VEC3_ADD1(VEC3_MUL1(tmp_color, specular_sum), 1.f));
	tmp_color = texture_bilinear(mat->texture, intersect->tex);
	return (VEC3_MIN(VEC3_MUL(tmp_color, light_sum), VEC3_1(1.f)));
}

static bool		refracted_ray(t_vertex const *ray, t_material const *mat1,
					t_material const *mat2, t_intersect const *intersect,
					t_vec3 *dst)
{
	float			index = mat1->refract_index / mat2->refract_index;
	float			tmp;
	float const		cos_t = VEC3_DOT(ray->dir, intersect->norm);

	tmp = index * index * (1.f - (cos_t * cos_t));
	if (tmp > 1.f)
		return (false);
	tmp = index * cos_t - sqrtf(1.f - tmp);
	*dst = ft_vec3norm(VEC3_ADD(VEC3_MUL1(ray->dir, index),
		VEC3_MUL1(intersect->norm, tmp)));
	return (true);
}

static t_vec3	trace_(t_scene const *scene, t_vertex const *ray,
					t_material const *mat1, t_material const *mat2,
					t_intersect const *intersect, uint32_t max_depth)
{
	t_vertex		tmp;
	t_vec3			reflected_color;
	t_vec3			refracted_color;
	float			reflection;

	reflection = mat2->reflection;
	tmp.pos = intersect->pos;
	if (reflection > 0.001f)
	{
		tmp.dir = ft_vec3norm(VEC3_ADD(ray->dir, VEC3_MUL1(intersect->norm,
			-2.f * VEC3_DOT(intersect->norm, ray->dir))));
		reflected_color = ray_trace(scene, &tmp, mat1, max_depth);
	}
	if (reflection < 0.999f)
	{
		if (!refracted_ray(ray, mat1, mat2, intersect, &tmp.dir))
			reflection = 1.f;
		else
			refracted_color = ray_trace(scene, &tmp, mat2, max_depth);
	}
	return (ft_vec3mix(reflected_color, refracted_color, reflection));
}

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray,
					t_material const *material, uint32_t max_depth)
{
	t_intersect			intersect;
	t_obj const			*obj;
	t_vec3				color;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (scene->sky_color);
	intersect.norm = ft_vec3norm(intersect.norm);
	color = ray_to_light(scene, &obj->material, ray, &intersect);
	if (obj->material.opacity < 0.999f && max_depth > 0)
		color = ft_vec3mix(color, trace_(scene, ray, material, &obj->material,
				&intersect, max_depth - 1), obj->material.opacity);
	return (color);
}
