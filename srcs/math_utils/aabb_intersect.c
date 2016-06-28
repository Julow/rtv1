/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:54:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/28 10:52:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

bool			aabb_intersect(t_aabb const *b, t_vertex const *ray, float *dst)
{
	float			t[6];
	float			tmin;
	float			tmax;

	t[0] = (b->a.x - ray->pos.x) / ray->dir.x;
	t[1] = (b->b.x - ray->pos.x) / ray->dir.x;
	t[2] = (b->a.y - ray->pos.y) / ray->dir.y;
	t[3] = (b->b.y - ray->pos.y) / ray->dir.y;
	t[4] = (b->a.z - ray->pos.z) / ray->dir.z;
	t[5] = (b->b.z - ray->pos.z) / ray->dir.z;
	ORDER(t[0], t[1]);
	ORDER(t[2], t[3]);
	ORDER(t[4], t[5]);
	tmin = MAX(MAX(t[0], t[2]), t[4]);
	tmax = MIN(MIN(t[1], t[3]), t[5]);
	if (tmax < 0.f || tmin > tmax)
		return (false);
	*dst = tmin;
	return (true);
}
