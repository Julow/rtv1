/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/04/02 19:28:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "math_utils.h"
#include "obj.h"

#include <math.h>

static bool		sphere_intersect(bool *out, float *dist, t_vertex const *ray)
{
	float			a;
	float			b;
	float			d;

	a = VEC3_DOT(ray->dir, ray->dir);
	b = VEC3_DOT(ray->pos, ray->dir) * 2;
	d = b * b - (4 * a * (VEC3_DOT(ray->pos, ray->pos) - 1.f));
	if (d == 0.f)
	{
		*dist = -b / (2.f * a);
		return (true);
	}
	else if (d > 0.f)
	{
		d = sqrtf(d);
		if ((*dist = (-b - d) / (2.f * a)) > INTERSECT_ERROR)
			return (true);
		else if ((*dist = (-b + d) / (2.f * a)) > INTERSECT_ERROR)
			return ((*out = true), true);
	}
	return (false);
}

bool			sphere_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	bool			out;

	out = false;
	if (!sphere_intersect(&out, &intersect->dist, ray))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, intersect->dist));
	intersect->norm = out ? VEC3_SUB(VEC3_0(), intersect->pos) : intersect->pos;
	intersect->tex = VEC2(
		atan2(intersect->norm.z, intersect->norm.x) / (2.f * M_PI) + 0.5f,
		asin(intersect->norm.y) / M_PI + 0.5f);
	return (true);
	(void)obj;
}
