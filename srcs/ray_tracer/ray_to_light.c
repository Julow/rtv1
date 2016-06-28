/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/28 14:15:42 by jaguillo         ###   ########.fr       */
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
** TODO: encode light intensity into rgb channels (normalize 0-1 only at the very end)
** TODO: using (1 - target_alpha) ^ distance_in_object to attenuate light rgb intensities
*/

static t_vec3	light_color(t_ray_tracer const *t, t_light const *light,
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
** TODO: (re)move specular
** TODO: update this (max_dist is gone)
*/

#define REINTERPRET_CAST(T, VAL)	({typeof(VAL) tmp = (VAL); *(T*)&tmp; })

t_vec3			ray_to_light(t_ray_tracer const *t, t_material const *mat,
					t_vertex const *ray, t_intersect const *intersect)
{
	uint32_t		i;
	t_light const	*light;
	t_vec3			light_sum;
	float			specular_sum;
	t_vec3			tmp_color;
	float			b;
	float			tmp;
	t_vec3			light_dir;

	i = 0;
	light_sum = VEC3_1(mat->ambient);
	specular_sum = 0.f;
	while (i < t->scene->lights.length)
	{

		light = VECTOR_GET(t->scene->lights, i++);
		light_dir = VEC3_SUB(light->pos, intersect->pos);
		tmp = ft_vec3length(light_dir);
		light_dir = VEC3_DIV1(light_dir, tmp);
		tmp_color = light_color(t, light, &intersect->pos, &light_dir);

		if ((b = VEC3_DOT(intersect->norm, light_dir) * (tmp * tmp)) <= 0.f
			|| VEC3_DOT(light_dir, VEC3_SUB(VEC3_0(), light->dir)) < light->cutoff)
			continue ;

		tmp = ft_vec3dot(intersect->norm, ft_vec3norm(VEC3_SUB(light_dir, ray->dir)));
		specular_sum += (tmp <= 0.f) ? 0.f : powf(tmp, mat->specular_exp) * b;
		light_sum = VEC3_ADD(light_sum, VEC3_MUL1(tmp_color, b));
	}

	tmp_color = (mat->specular_map != NULL) ?
		REINTERPRET_CAST(t_vec3, TEXTURE_GET(mat->specular_map, intersect->tex))
		: VEC3_1(1.f);
	light_sum = VEC3_MUL(light_sum, VEC3_ADD1(VEC3_MUL1(tmp_color, specular_sum), 1.f));
	return (light_sum);
}
