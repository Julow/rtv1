/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:23:40 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:50:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "internal.h"
#include "math_utils.h"

#include <math.h>

#define CYLINDER_MIN		-0.5f
#define CYLINDER_MAX		0.5f

static bool		cylinder_check(float dist, t_vertex const *ray)
{
	float const		z = ray->dir.z * dist + ray->pos.z;

	if (dist > INTERSECT_ERROR && z >= CYLINDER_MIN && z <= CYLINDER_MAX)
		return (true);
	return (false);
}

static bool		cylinder_intersect(bool *out, float *dist, t_vertex const *ray)
{
	float			a;
	float			b;
	float			d;

	a = VEC2_DOT(ray->dir, ray->dir) * 2.f;
	b = VEC2_DOT(ray->pos, ray->dir) * 2.f;
	d = b * b - (2.f * a * (VEC2_DOT(ray->pos, ray->pos) - 1.f));
	if (d >= 0.f)
	{
		if (d != 0.f)
			d = sqrtf(d);
		if (cylinder_check((*dist = (-b - d) / a), ray))
			return (true);
		if (cylinder_check((*dist = (-b + d) / a), ray))
			return ((*out = true), true);
	}
	return (false);
}

bool			cylinder_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			dist;
	bool			out;

	out = false;
	if (!cylinder_intersect(&out, &dist, ray))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, dist));
	intersect->dir = VEC3_Z(intersect->pos, 0.f);
	if (out)
		intersect->dir = VEC3_SUB(VEC3_0(), intersect->dir);
	return (true);
	(void)obj;
}
