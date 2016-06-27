/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/27 18:13:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
#include "ft/math_mat3.h"
#include "ft/math_vec3.h"
#include "ft/math_vec4.h"

#include "internal.h"
#include "texture.h"

#include <math.h>

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

static void		trace_reflection(t_ray_tracer *t, t_vertex const *ray,
					t_material const *material, t_intersect const *intersect,
					t_vec3 *color)
{
	t_vertex		tmp;
	t_vec3			res;

	if (material->reflection < 0.001f)
		return ;
	tmp.pos = intersect->pos;
	tmp.dir = ft_vec3norm(VEC3_ADD(ray->dir, VEC3_MUL1(intersect->norm,
		-2.f * VEC3_DOT(intersect->norm, ray->dir))));
	if (ray_trace(t, &tmp, &res))
		*color = ft_vec3mix(res, *color, material->reflection);
}

static void		trace_refraction(t_ray_tracer *t, t_vertex const *ray,
					t_material const *material, t_intersect const *intersect,
					t_vec3 *color, float w)
{
	t_vertex		tmp;
	t_vec3			res;

	if (w < 0.999f && refracted_ray(ray, material, intersect, &tmp.dir))
	{
		tmp.pos = intersect->pos;
		if (ray_trace(t, &tmp, &res))
			*color = ft_vec3mix(*color, res, w); // TODO: VEC3_LERP macro
	}
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
	map_normal = TEXTURE_GET(obj->material.normal_map, intersect->tex);
	intersect->norm = ft_vec3norm(VEC3_SUB1(VEC3_MUL1(map_normal, 2.f), 1.f));
	ft_mat3apply(&tbn, &intersect->norm);
}

bool			ray_trace(t_ray_tracer *t, t_vertex const *ray,
					t_vec3 *result)
{
	t_intersect			intersect;
	t_obj const			*obj;
	t_vec3				light;
	t_vec4				color;

	if ((obj = nearest_intersect(&intersect, t->scene, *ray)) == NULL)
		return (false);
	intersect.norm = ft_vec3norm(intersect.norm);
	if (obj->material.normal_map != NULL)
		apply_normal_map(obj, &intersect);
	color = TEXTURE_GET(obj->material.texture, intersect.tex);
	light = ray_to_light(t, &obj->material, ray, &intersect);
	*result = VEC3_MUL(color, light);
	if (t->depth > 0)
	{
		t->depth--;
		trace_refraction(t, ray, &obj->material, &intersect, result, color.w);
		trace_reflection(t, ray, &obj->material, &intersect, result);
		t->depth++;
	}
	return (true);
}
