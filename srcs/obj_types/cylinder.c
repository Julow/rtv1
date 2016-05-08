/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:23:40 by juloo             #+#    #+#             */
/*   Updated: 2016/05/08 14:30:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "math_utils.h"
#include "obj.h"

#include <math.h>

#define CYLINDER_MIN		-1.f
#define CYLINDER_MAX		1.f

static bool		cylinder_check_side(float dist, t_vertex const *ray)
{
	float const		tmp = ray->dir.z * dist + ray->pos.z;

	return (tmp >= CYLINDER_MIN && tmp <= CYLINDER_MAX);
}

static bool		cylinder_check_base(float dist, t_vertex const *ray)
{
	t_vec2 const	tmp = VEC2_ADD(ray->pos, VEC2_MUL1(ray->dir, dist));

	return (VEC2_DOT(tmp, tmp) <= 1.f);
}

static bool		cylinder_side(t_vec2 *dist, t_vertex const *ray)
{
	float const		a = VEC2_DOT(ray->dir, ray->dir) * 2.f;
	float const		b = VEC2_DOT(ray->pos, ray->dir) * 2.f;
	float			d;

	d = b * b - (2.f * a * (VEC2_DOT(ray->pos, ray->pos) - 1.f));
	if (d < 0.f)
		return (false);
	if (d != 0.f)
		d = sqrtf(d);
	*dist = VEC2((-b - d) / a, (-b + d) / a);
	if (!cylinder_check_side(dist->x, ray))
	{
		if (!cylinder_check_side(dist->y, ray))
			return (false);
		dist->x = dist->y;
	}
	else if (!cylinder_check_side(dist->y, ray))
		dist->y = dist->x;
	return (true);
}

static bool		cylinder_base(t_vec2 *dist, t_vertex const *ray)
{
	if (ray->dir.z == 0.f)
		return (false);
	*dist = VEC2((CYLINDER_MIN - ray->pos.z) / ray->dir.z,
			(CYLINDER_MAX - ray->pos.z) / ray->dir.z);
	if (dist->x > dist->y)
		*dist = VEC2(dist->y, dist->x);
	if (!cylinder_check_base(dist->x, ray))
	{
		if (!cylinder_check_base(dist->y, ray))
			return (false);
		dist->x = dist->y;
	}
	else if (!cylinder_check_base(dist->y, ray))
		dist->y = dist->x;
	return (true);
}

static bool		cylinder_intersect(t_vec2 *dist, bool *base,
					t_vertex const *ray)
{
	t_vec2			tmp;

	if (!cylinder_side(dist, ray))
	{
		if (!cylinder_base(dist, ray))
			return (false);
		base[0] = true;
		base[1] = true;
	}
	else if (!cylinder_base(&tmp, ray))
	{
		base[0] = false;
		base[1] = false;
	}
	else
	{
		dist->x = (base[0] = (tmp.x < dist->x)) ? tmp.x : dist->x;
		dist->y = (base[1] = (tmp.y > dist->y)) ? tmp.y : dist->y;
	}
	return (true);
}

static void		load_intersect(bool base, bool out, float dist,
					t_vertex const *ray, t_intersect *intersect)
{
	intersect->dist = dist;
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, dist));
	if (base)
		intersect->norm = VEC3(0.f, 0.f, (ray->dir.z < 0.f) ? 1.f : -1.f);
	else
		intersect->norm = VEC3_Z(intersect->pos, 0.f);
	if (out)
		intersect->norm = VEC3_SUB(VEC3_0(), intersect->norm);
	if (base)
		intersect->tex = VEC2(intersect->pos.x, intersect->pos.y);
	else
		intersect->tex = VEC2(
			atan2(intersect->norm.x, intersect->norm.y) / (2.f * M_PI) + 0.5f,
			(intersect->pos.z - CYLINDER_MIN) / (CYLINDER_MAX - CYLINDER_MIN));
}

bool			cylinder_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect)
{
	t_vec2			dist;
	bool			base[2];

	if (!cylinder_intersect(&dist, base, ray)
		|| (dist.x < 0.f && dist.y < 0.f))
		return (false);
	if (both)
	{
		load_intersect(base[0], false, dist.x, ray, &intersect[0]);
		load_intersect(base[1], true, dist.y, ray, &intersect[1]);
	}
	else if (dist.x < 0.f)
		load_intersect(base[1], true, dist.y, ray, intersect);
	else
		load_intersect(base[0], false, dist.x, ray, intersect);
	return (true);
	(void)obj;
}
