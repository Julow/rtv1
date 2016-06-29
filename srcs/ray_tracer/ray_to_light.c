/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 17:20:18 by jaguillo         ###   ########.fr       */
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
** light through objects:
**  light_rgb =
**  	LERP(obj_rgb * (1 - obj_a) * light_rgb * obj_a, light_rgb, obj_a)
** -
** TODO: attenuation: (1 - target_alpha) ^ distance_in_object
*/

static t_vec3	light_color(t_ray_tracer *t, t_light const *light,
					t_vec3 const *intersect_pos, t_vec3 const *light_dir)
{
	t_vertex		ray;
	t_obj const		*obj;
	t_vec3			color;
	t_intersect		intersect;
	t_vec4			obj_color;

	ray = VERTEX(light->pos, VEC3_SUB(VEC3_0(), *light_dir));
	color = light->color;
	while ((obj = nearest_intersect(&intersect, t->scene, ray)) != NULL)
	{
		if (ft_vec3dist2(*intersect_pos, intersect.pos) <= RAY_ERROR)
			break ;
		obj_color = TEXTURE_GET(obj->material.texture, intersect.tex);
		color = VEC3_MUL(color, VEC3_SUB1(
				VEC3_MUL1(obj_color, obj_color.w * (1 - obj_color.w)),
				obj_color.w - 1));
		ray.pos = intersect.pos;
	}
	return (color);
}

/*
** light:
**  light_dir = norm(light_pos - intrsc_pos)
**  b = dot(intrsc_norm, light_dir)
** spot light:
**  b *= (dot(light_dir, -spot_dir) < spot_cutoff)
** sum:
**  light_sum += light_rgb * b
** -
** TODO: update this (max_dist is gone)
*/

#define REINTERPRET_CAST(T, VAL)	({typeof(VAL) tmp = (VAL); *(T*)&tmp; })

t_vec3			ray_to_light(t_ray_tracer *t, t_material const *mat,
					t_vertex const *ray, t_intersect const *intersect)
{
	t_light const	*light;
	t_vec3			light_sum;
	t_vec3			tmp;
	float			b;
	t_vec3			light_dir;

	light_sum = VEC3_1(mat->ambient);
	light = VECTOR_IT(t->scene->lights);
	while (VECTOR_NEXT(t->scene->lights, light))
	{
		light_dir = VEC3_SUB(light->pos, intersect->pos);
		b = ft_vec3length(light_dir);
		light_dir = VEC3_DIV1(light_dir, b);
		if ((b = VEC3_DOT(intersect->norm, light_dir) * (b * b)) <= 0.f
			|| VEC3_DOT(light_dir,
					VEC3_SUB(VEC3_0(), light->dir)) < light->cutoff)
			continue ;
		tmp = light_color(t, light, &intersect->pos, &light_dir);
		light_sum = VEC3_ADD(light_sum, VEC3_MUL1(tmp, b));
	}
	return (light_sum);
}
