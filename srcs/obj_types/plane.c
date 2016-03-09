/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:37:19 by juloo             #+#    #+#             */
/*   Updated: 2016/03/09 01:53:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "internal.h"
#include "math_utils.h"

#include <math.h>

#define PLANE_MIN	(VEC2(-0.5f, -0.5f))
#define PLANE_MAX	(VEC2(0.5f, 0.5f))

bool			plane_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			tmp;

	if (ray->dir.y == 0.f)
		return (false);
	tmp = -ray->pos.y / ray->dir.y;
	if (tmp < 0)
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, tmp));
	if (intersect->pos.x < PLANE_MIN.x || intersect->pos.x > PLANE_MAX.x
		|| intersect->pos.z < PLANE_MIN.y || intersect->pos.z > PLANE_MAX.y)
		return (false);
	intersect->dir = VEC3(0.f, (ray->dir.y < 0.f) ? 1.f : -1.f, 0.f);
	return (true);
	(void)obj;
}
