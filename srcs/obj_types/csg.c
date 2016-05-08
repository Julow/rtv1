/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:52:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/08 17:23:26 by juloo            ###   ########.fr       */
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
	if (!obj->type->ray_intersect(obj, &tmp, true, dst))
		return (false);
	ft_mat4apply_vec3(&obj->m, &dst->pos, 1.f);
	ft_mat4apply_vec3(&obj->m, &dst->norm, 0.f);
	return (true);
}

/*
** MIN(a_min, b_min), MAX(a_max, b_max)
** TODO: test with non adjacent objects
*/
bool			or_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *dst)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[4];
	bool						b[2];
	t_vec2u						i;

	b[0] = ray_intersect(intrsct + 0, objs[0], ray);
	b[1] = ray_intersect(intrsct + 2, objs[1], ray);
	if (b[0] && b[1])
		i = VEC2U((intrsct[0].dist < intrsct[2].dist) ? 0 : 2,
			(intrsct[1].dist > intrsct[3].dist) ? 1 : 3);
	else if (b[0] || b[1])
		i = b[0] ? VEC2U(0, 1) : VEC2U(2, 3);
	else
		return (false);
	if (both)
	{
		dst[0] = intrsct[i.x];
		dst[1] = intrsct[i.y];
	}
	else
	{
		*dst = intrsct[(intrsct[i.x].dist < 0.f) ? i.y : i.x];
	}
	return (true);
}

/*
** MAX(a_min, b_min), MIN(a_max, b_max)
*/
bool			and_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *dst)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[4];
	bool						b[2];
	t_vec2u						i;

	b[0] = ray_intersect(intrsct + 0, objs[0], ray);
	b[1] = ray_intersect(intrsct + 2, objs[1], ray);
	if (!b[0] || !b[1])
		return (false);
	i = VEC2U((intrsct[0].dist > intrsct[2].dist) ? 0 : 2,
		(intrsct[1].dist < intrsct[3].dist) ? 1 : 3);
	if (intrsct[i.x].dist >= intrsct[i.y].dist)
		return (false);
	if (both)
	{
		dst[0] = intrsct[i.x];
		dst[1] = intrsct[i.y];
	}
	else
	{
		*dst = intrsct[(intrsct[i.x].dist < 0.f) ? i.y : i.x];
	}
	return (true);
}

/*
** a_min, MIN(a_max, b_min) if a_min < b_min
** MAX(a_min, b_max), a_max else
*/
bool			not_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *dst)
{
	t_obj const *const *const	objs = ENDOF(obj);
	t_intersect					intrsct[4];
	bool						b[2];
	t_vec2u						i;

	b[0] = ray_intersect(intrsct + 0, objs[0], ray);
	b[1] = ray_intersect(intrsct + 2, objs[1], ray);
	if (!b[0])
		return (false);
	if (!b[1])
		i = VEC2U(0, 1);
	else if (intrsct[0].dist < intrsct[2].dist)
		i = VEC2U(0, (intrsct[1].dist < intrsct[2].dist) ? 1 : 2);
	else
		i = VEC2U((intrsct[0].dist > intrsct[3].dist) ? 0 : 3, 1);
	if (intrsct[i.x].dist >= intrsct[i.y].dist)
		return (false);
	if (i.x & 1)
		intrsct[i.x].norm = VEC3_SUB(VEC3_0(), intrsct[i.x].norm);
	if (!(i.y & 1))
		intrsct[i.y].norm = VEC3_SUB(VEC3_0(), intrsct[i.y].norm);
	if (both)
	{
		dst[0] = intrsct[i.x];
		dst[1] = intrsct[i.y];
	}
	else
	{
		*dst = intrsct[(intrsct[i.x].dist < 0.f) ? i.y : i.x];
	}
	return (true);
}
