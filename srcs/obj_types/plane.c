/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:37:19 by juloo             #+#    #+#             */
/*   Updated: 2016/05/08 00:27:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "math_utils.h"
#include "obj.h"

#include <math.h>

#define PLANE_MIN	(VEC2(-0.5f, -0.5f))
#define PLANE_MAX	(VEC2(0.5f, 0.5f))

bool			plane_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			dist;

	if (ray->dir.y == 0.f || (dist = -ray->pos.y / ray->dir.y) < 0.f)
		return (false);
	intersect->dist = VEC2(dist, dist);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, dist));
	if (intersect->pos.x < PLANE_MIN.x || intersect->pos.x > PLANE_MAX.x
		|| intersect->pos.z < PLANE_MIN.y || intersect->pos.z > PLANE_MAX.y)
		return (false);
	intersect->norm = VEC3(0.f, (ray->dir.y < 0.f) ? 1.f : -1.f, 0.f);
	intersect->tex = VEC2(intersect->pos.x - PLANE_MIN.x,
		intersect->pos.z - PLANE_MIN.y);
	return (true);
	(void)obj;
}
