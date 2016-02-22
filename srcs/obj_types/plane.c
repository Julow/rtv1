/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:37:19 by juloo             #+#    #+#             */
/*   Updated: 2016/02/22 22:28:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "math_utils.h"
#include "obj_types.h"

#include <math.h>

static bool		plane_ray_intersect(t_vertex *intersect, t_plane const *obj,
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

t_plane			*plane_new(void)
{
	static t_obj_class const	plane_class = {
		SUBC("plane"),
		V(&plane_ray_intersect),
	};
	t_plane *const				plane = NEW(t_plane);

	ft_bzero(plane, sizeof(t_plane));
	plane->obj.type = &plane_class;
	return (plane);
}
