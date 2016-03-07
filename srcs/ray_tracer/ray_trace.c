/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/07 14:32:06 by jaguillo         ###   ########.fr       */
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

static bool		refracted_ray(t_vertex const *ray, t_material const *mat1,
					t_material const *mat2, t_vertex const *intersect,
					t_vec3 *dst)
{
	float			index = mat1->refract_index / mat2->refract_index;
	float			tmp;
	float const		cos_t = VEC3_DOT(ray->dir, intersect->dir);

	tmp = index * index * (1.f - (cos_t * cos_t));
	if (tmp > 1.f)
		return (false);
	tmp = index * cos_t - sqrtf(1.f - tmp);
	*dst = ft_vec3norm(VEC3_ADD(VEC3_MUL1(ray->dir, index),
		VEC3_MUL1(intersect->dir, tmp)));
	return (true);
}

static t_vec3	trace_(t_scene const *scene, t_vertex const *ray,
					t_material const *mat1, t_material const *mat2,
					t_vertex const *intersect, uint32_t max_depth)
{
	t_vertex		tmp;
	t_vec3			reflected_color;
	t_vec3			refracted_color;
	float			reflection;

	reflection = mat2->reflection;
	tmp.pos = intersect->pos;
	if (reflection > 0.001f)
	{
		tmp.dir = ft_vec3norm(VEC3_ADD(ray->dir, VEC3_MUL1(intersect->dir,
			-2.f * VEC3_DOT(intersect->dir, ray->dir))));
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
	t_vertex			intersect;
	t_obj const			*obj;
	t_vec3				color;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (scene->sky_color);
	color = ray_to_light(scene, &obj->material, ray, &intersect);
	if (obj->material.opacity < 0.999f && max_depth > 0)
		color = ft_vec3mix(color, trace_(scene, ray, material, &obj->material,
				&intersect, max_depth - 1), obj->material.opacity);
	return (color);
}
