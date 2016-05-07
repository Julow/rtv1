/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/08 00:41:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "math_utils.h"
#include "obj.h"

#include <math.h>

static bool		sphere_intersect(t_vec2 *dist, t_vertex const *ray)
{
	float const		a = VEC3_DOT(ray->dir, ray->dir) * 2.f;
	float const		b = VEC3_DOT(ray->pos, ray->dir) * 2.f;
	float			d;

	d = b * b - (2.f * a * (VEC3_DOT(ray->pos, ray->pos) - 1.f));
	if (d < 0.f)
		return (false);
	if (d != 0.f)
		d = sqrtf(d);
	*dist = VEC2((-b - d) / a, (-b + d) / a);
	return (true);
}

bool			sphere_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	if (!sphere_intersect(&intersect->dist, ray)
		|| (intersect->dist.x < 0.f && intersect->dist.y < 0.f))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir,
			(intersect->dist.x < 0.f) ? intersect->dist.y : intersect->dist.x));
	if (intersect->dist.x < 0.f)
		intersect->norm = VEC3_SUB(VEC3_0(), intersect->pos);
	else
		intersect->norm = intersect->pos;
	intersect->tex = VEC2(
		atan2(intersect->norm.z, intersect->norm.x) / (2.f * M_PI) + 0.5f,
		asin(intersect->norm.y) / M_PI + 0.5f);
	return (true);
	(void)obj;
}
