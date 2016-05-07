/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:41:16 by juloo             #+#    #+#             */
/*   Updated: 2016/05/08 00:02:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "math_utils.h"
#include "obj.h"

#include <math.h>

#define CONE_MIN		0.f
#define CONE_MAX		1.f

static bool		cone_check_side(float dist, t_vertex const *ray)
{
	float const		z = ray->dir.z * dist + ray->pos.z;

	return (z >= CONE_MIN && z <= CONE_MAX);
}

static bool		cone_side(t_vec2 *dist, t_vertex const *ray)
{
	float			a;
	float			b;
	float			d;

	a = (VEC2_DOT(ray->dir, ray->dir) - (ray->dir.z * ray->dir.z)) * 2.f;
	b = (VEC2_DOT(ray->pos, ray->dir) - (ray->pos.z * ray->dir.z)) * 2.f;
	d = b * b - (2.f * a
			* (VEC2_DOT(ray->pos, ray->pos) - (ray->pos.z * ray->pos.z)));
	if (d < 0.f)
		return (false);
	if (d != 0.f)
		d = sqrtf(d);
	*dist = VEC2((-b - d) / a, (-b + d) / a);
	if (!cone_check_side(dist->x, ray))
	{
		if (!cone_check_side(dist->y, ray))
			return (false);
		dist->x = dist->y;
	}
	else if (!cone_check_side(dist->y, ray))
		dist->y = dist->x;
	return (true);
}

static bool		cone_base(float *dist, t_vertex const *ray)
{
	t_vec2			tmp;

	if (ray->dir.z == 0.f)
		return (false);
	*dist = (CONE_MAX - ray->pos.z) / ray->dir.z;
	tmp = VEC2_ADD(ray->pos, VEC2_MUL1(ray->dir, *dist));
	return (VEC2_DOT(tmp, tmp) <= 1.f);
}

static bool		cone_intersect(t_vec2 *dist, bool *base, t_vertex const *ray)
{
	float			tmp;

	if (!cone_side(dist, ray))
	{
		if (!cone_base(&tmp, ray))
			return (false);
		*dist = VEC2(tmp, tmp);
		*base = true;
	}
	else if (!cone_base(&tmp, ray))
	{
		*base = false;
	}
	else
	{
		dist->x = (*base = (tmp < dist->x)) ? tmp : dist->x;
		dist->y = MAX(tmp, dist->y);
	}
	return (true);
}

bool			cone_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	t_vec2			dist;
	bool			base;

	if (!cone_intersect(&dist, &base, ray)
		|| (intersect->dist = (dist.x < 0.f) ? dist.y : dist.x) < 0.f)
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, intersect->dist));
	if (base)
		intersect->norm = VEC3(0, 0, 1.f);
	else
		intersect->norm = ft_vec3norm(VEC3_Z(intersect->pos, -intersect->pos.z));
	if (dist.x < 0.f)
		intersect->norm = VEC3_SUB(VEC3_0(), intersect->norm);
	if (base)
		intersect->tex = VEC2(intersect->pos.x, intersect->pos.y);
	else
		intersect->tex = VEC2(intersect->norm.z, intersect->norm.y / 2.f + 0.5f);
	return (true);
	(void)obj;
}
