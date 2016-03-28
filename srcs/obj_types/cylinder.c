/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:23:40 by juloo             #+#    #+#             */
/*   Updated: 2016/03/28 12:50:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "internal.h"
#include "math_utils.h"

#include <math.h>

#define CYLINDER_MIN		-1.f
#define CYLINDER_MAX		1.f

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

bool			cylinder_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	bool			out;

	out = false;
	if (!cylinder_intersect(&out, &intersect->dist, ray))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, intersect->dist));
	intersect->norm = VEC3_Z(intersect->pos, 0.f);
	if (out)
		intersect->norm = VEC3_SUB(VEC3_0(), intersect->norm);
	intersect->tex = VEC2((intersect->pos.z - CYLINDER_MIN) / (CYLINDER_MAX - CYLINDER_MIN),
		intersect->norm.y / 2.f + 0.5f);
	return (true);
	(void)obj;
}
