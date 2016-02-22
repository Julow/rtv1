/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:37:19 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 00:02:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "math_utils.h"
#include "obj_types.h"

#include <math.h>

static bool		plane_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	float			tmp;

	tmp = ray->dir.y;
	if (tmp >= 0.f)
		return (false);
	tmp = -ray->pos.y / tmp;
	if (tmp < 0)
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, tmp));
	intersect->dir = VEC3(0.f, 1.f, 0.f);
	return (true);
}

t_obj			*plane_new(void)
{
	static t_obj_class const	plane_class = {
		SUBC("plane"),
		V(&plane_ray_intersect),
	};
	t_obj *const				plane = NEW(t_obj);

	ft_bzero(plane, sizeof(t_obj));
	plane->type = &plane_class;
	return (plane);
}
