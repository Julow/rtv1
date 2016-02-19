/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 14:58:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include <math.h>

#define ATTENUATION_DIST		1000.f
#define ATTENUATION_EXP			4

static float	nearest_dist(t_scene const *scene, t_vertex const *ray)
{
	t_vertex		intersect;

	if (nearest_intersect(&intersect, scene, *ray) == NULL)
		return (HUGE_VAL);
	return (ft_vec3dist(ray->pos, intersect.pos));
}

float			ray_to_light(t_scene const *scene, t_vertex const *ray)
{
	uint32_t		i;
	t_light const	*light;
	float			light_sum;
	float			tmp;
	float			attenuation;
	t_vec3			light_dir;

	i = 0;
	light_sum = 0.f;
	while (i < scene->lights.length)
	{
		light = VECTOR_GET(scene->lights, i++);
		light_dir = VEC3_SUB(light->pos, ray->pos);
		tmp = ft_vec3length(light_dir);
		if (tmp > nearest_dist(scene, &VERTEX(ray->pos, light_dir))
			|| (attenuation = 1.f - tmp / ATTENUATION_DIST) <= 0.f
			|| (tmp = VEC3_DOT(ray->dir, VEC3_DIV1(light_dir, tmp))) < 0.f)
			continue ;
		light_sum += light->light * tmp * powf(attenuation, ATTENUATION_EXP);
	}
	return (light_sum);
}

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray)
{
	t_vertex			intersect;
	t_obj const			*obj;
	float				light;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (scene->sky_color);
	light = ray_to_light(scene, &intersect);
	return (VEC3_MUL1(obj->color, MIN(light, 1.f)));
}
