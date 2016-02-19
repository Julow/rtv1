/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 00:42:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include <math.h>

#define VEC3_DOT(A, B)	(((A).x * (B).x) + ((A).y * (B).y) + ((A).z * (B).z))

/*
** Return true if 'a' is nearest of 'pos' than 'b'
**  false otherwise
*/
bool			is_nearest_than(t_vec3 const *pos, t_vec3 a, t_vec3 b)
{
	a = VEC3_SUB(*pos, a);
	b = VEC3_SUB(*pos, b);
	if (ft_vec3dot(a, a) <= ft_vec3dot(b, b))
		return (true);
	return (false);
}

float			ft_vec3length(t_vec3 v)
{
	return (sqrtf(VEC3_DOT(v, v)));
}

float			ft_vec3dist(t_vec3 a, t_vec3 b)
{
	a = VEC3_SUB(a, b);
	return (sqrtf(VEC3_DOT(a, a)));
}

t_obj const		*nearest_intersect(t_vertex *dst, t_scene const *scene,
					t_vertex ray)
{
	t_obj const		*obj;
	uint32_t		i;
	t_obj const		*nearest;
	t_vertex		intersect;

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, 0.001f));
	nearest = NULL;
	i = 0;
	while (i < scene->objs.length)
	{
		obj = VGET(t_obj const*, scene->objs, i++);
		if (obj->type->ray_intersect(&intersect, obj, &ray) && (nearest == NULL
				|| is_nearest_than(&ray.pos, intersect.pos, dst->pos)))
		{
			nearest = obj;
			*dst = intersect;
		}
	}
	return (nearest);
}

#define ATTENUATION_DIST		8
#define ATTENUATION_EXP			4

float			nearest_dist(t_scene const *scene, t_vertex const *ray)
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

#define VEC4_TO3(V)		(*(t_vec3 const*)&(V))

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray)
{
	t_vertex			intersect;
	t_obj const			*obj;
	float				light;

	if ((obj = nearest_intersect(&intersect, scene, *ray)) == NULL)
		return (scene->sky_color);
	light = ray_to_light(scene, &intersect);
	return (VEC3_MUL1(VEC4_TO3(obj->color), light));
}
