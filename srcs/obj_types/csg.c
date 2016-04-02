/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:52:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/04/02 17:45:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_types.h"

static bool		ray_intersect(t_intersect *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_vertex		tmp;

	tmp = *ray;
	ft_mat4apply_vec3(&obj->m_inv, &tmp.pos, 1.f);
	ft_mat4apply_vec3(&obj->m_inv, &tmp.dir, 0.f);
	if (!obj->type->ray_intersect(dst, obj, &tmp))
		return (false);
	ft_mat4apply_vec3(&obj->m, &dst->pos, 1.f);
	ft_mat4apply_vec3(&obj->m, &dst->norm, 0.f);
	return (true);
}

bool			or_ray_intersect(t_intersect *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[2];
	bool						b[2];

	b[0] = ray_intersect(&intrsct[0], objs[0], ray);
	b[1] = ray_intersect(&intrsct[1], objs[1], ray);
	if (b[0])
		*dst = intrsct[(b[1] && intrsct[0].dist > intrsct[1].dist) ? 1 : 0];
	else if (b[1])
		*dst = intrsct[1];
	else
		return (false);
	return (true);
}

bool			and_ray_intersect(t_intersect *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[2];
	bool						b[2];

	b[0] = ray_intersect(&intrsct[0], objs[0], ray);
	b[1] = ray_intersect(&intrsct[1], objs[1], ray);
	if (!b[0] || !b[1])
		return (false);
	*dst = intrsct[(intrsct[0].dist > intrsct[1].dist) ? 0 : 1];
	return (true);
}

bool			not_ray_intersect(t_intersect *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[2];
	bool						b[2];
	t_vertex					tmp;

	if (!(b[0] = ray_intersect(&intrsct[0], objs[0], ray)))
		return (false);
	b[1] = ray_intersect(&intrsct[1], objs[1], ray);
	if (!b[1] || intrsct[1].dist >= intrsct[0].dist)
	{
		*dst = intrsct[0];
		return (true);
	}
	tmp.pos = VEC3_ADD(intrsct[0].pos, VEC3_MUL1(ray->dir, RAY_ERROR));
	tmp.dir = ray->dir;
	if (!(b[0] = ray_intersect(&intrsct[0], objs[0], &tmp)))
		return (false);
	if ((b[1] = ray_intersect(&intrsct[1], objs[1], &tmp))
		&& intrsct[1].dist >= intrsct[0].dist)
		return (false);
	*dst = intrsct[(b[1] && intrsct[1].dist < intrsct[0].dist) ? 1 : 0];
	return (true);
}
