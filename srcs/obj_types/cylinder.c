/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:23:40 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 18:14:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "internal.h"
#include "math_utils.h"

#include <math.h>

bool			cylinder_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			a;
	float			b;
	float			d;
	float			tmp;

	a = VEC2_DOT(ray->dir, ray->dir);
	b = VEC2_DOT(ray->pos, ray->dir) * 2;
	d = b * b - (4 * a * (VEC2_DOT(ray->pos, ray->pos) - 1.f));
	if (d == 0.f)
		tmp = -b / (2.f * a);
	else if (d < 0.f || ((tmp = (-b - sqrt(d)) / (2.f * a)) < 0.f
			&& (tmp = (-b + sqrt(d)) / (2.f * a)) < 0.f))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, tmp));
	intersect->dir = VEC3_Z(intersect->pos, 0.f);
	return (true);
}
