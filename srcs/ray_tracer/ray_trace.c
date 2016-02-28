/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/28 01:49:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include <math.h>

#define ATTENUATION_DIST		1000.f
#define ATTENUATION_EXP			4

#define VEC3_MIN(A, B)	(VEC3(MIN(A.x, B.x), MIN(A.y, B.y), MIN(A.z, B.z)))

static float	nearest_dist2(t_scene const *scene, t_vertex const *ray)
{
	t_vertex		intersect;

	if (nearest_intersect(&intersect, scene, *ray) == NULL)
		return (HUGE_VAL);
	return (ft_vec3dist2(ray->pos, intersect.pos));
}

t_vec3			ray_to_light(t_scene const *scene, t_material const *mat,
					t_vertex const *ray, t_vertex const *intersect)
{
	uint32_t		i;
	t_light const	*light;
	t_vec3			light_sum;
	t_vec3			specular;
	float			tmp;
	float			tmp2;
	t_vec3			light_dir;

	i = 0;
	light_sum = VEC3_0();
	while (i < scene->lights.length)
	{
		light = VECTOR_GET(scene->lights, i++);
		light_dir = VEC3_SUB(light->pos, intersect->pos);
		tmp = ft_vec3length(light_dir);
		light_dir = VEC3_DIV1(light_dir, tmp);
		if ((tmp * tmp) > nearest_dist2(scene, &VERTEX(intersect->pos, light_dir))
			|| (tmp2 = 1.f - tmp / ATTENUATION_DIST) <= 0.f
			|| (tmp = VEC3_DOT(intersect->dir, light_dir)) < 0.f)
			continue ;
		tmp = light->brightness * tmp * powf(tmp2, ATTENUATION_EXP);
		tmp2 = ft_vec3dot(intersect->dir,
			ft_vec3norm(VEC3_SUB(light_dir, ray->dir)));
		tmp2 = (tmp2 <= 0.f) ? 0.f : powf(tmp2, mat->specular_exp);
		specular = VEC3_MUL1(mat->specular_color, tmp2);
		light_sum = VEC3_ADD(light_sum, VEC3_MUL1(VEC3_MUL(
			VEC3_ADD(mat->color, specular), light->color), tmp));
	}
	return (VEC3_MIN(light_sum, VEC3_1(1.f)));
}

static t_vec3	trace_reflect(t_scene const *scene, t_vertex const *ray,
					t_material const *material, t_vertex const *intersect,
					uint32_t ray_depth)
{
	t_vertex		reflected;

	reflected.pos = intersect->pos;
	reflected.dir = ft_vec3norm(VEC3_ADD(ray->dir,
		VEC3_MUL1(intersect->dir, -2 * VEC3_DOT(intersect->dir, ray->dir))));
	return (ray_trace(scene, &reflected, material, ray_depth));
}

static t_vec3	trace_refract(t_scene const *scene, t_vertex const *ray,
					t_material const *material, t_material const *obj_mat,
					t_vertex const *intersect, uint32_t ray_depth)
{
	t_vertex		refracted;
	float			index = material->refract_index / obj_mat->refract_index;
	float			tmp;

	tmp = VEC3_DOT(ray->dir, intersect->dir);
	tmp = index * tmp - sqrt(1.f - (index * index * (1.f - (tmp * tmp))));
	refracted.pos = intersect->pos;
	refracted.dir = ft_vec3norm(VEC3_ADD(VEC3_MUL1(ray->dir, index),
		VEC3_MUL1(intersect->dir, tmp)));
	return (ray_trace(scene, &refracted, obj_mat, ray_depth));
}

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray,
					t_material const *material, uint32_t max_depth)
{
	t_vertex			intersect;
	t_obj const			*obj;
	t_vec3				color;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (scene->sky_color);
	color = ray_to_light(scene, &obj->material, ray, &intersect);
	if (obj->material.opacity < 0.999f && max_depth > 0)
		color = ft_vec3mix(color,
			ft_vec3mix(trace_reflect(scene, ray, material, &intersect, max_depth - 1),
				trace_refract(scene, ray, material, &obj->material, &intersect, max_depth - 1),
				obj->material.reflection),
			obj->material.opacity);
	return (color);
}
