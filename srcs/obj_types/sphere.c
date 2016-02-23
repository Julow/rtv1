/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/23 18:14:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "internal.h"
#include "math_utils.h"

#include <math.h>

bool			sphere_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			a;
	float			b;
	float			d;
	float			tmp;

	a = VEC3_DOT(ray->dir, ray->dir);
	b = VEC3_DOT(ray->pos, ray->dir) * 2;
	d = b * b - (4 * a * (VEC3_DOT(ray->pos, ray->pos) - 1.f));
	if (d == 0.f)
		tmp = -b / (2.f * a);
	else if (d < 0.f || ((tmp = (-b - sqrt(d)) / (2.f * a)) < 0.f
			&& (tmp = (-b + sqrt(d)) / (2.f * a)) < 0.f))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, tmp));
	intersect->dir = intersect->pos;
	return (true);
}
