/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/02/19 11:32:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** Return true if 'a' is nearest of 'pos' than 'b'
**  false otherwise
*/
static bool		is_nearest_than(t_vec3 const *pos, t_vec3 a, t_vec3 b)
{
	a = VEC3_SUB(*pos, a);
	b = VEC3_SUB(*pos, b);
	if (VEC3_DOT(a, a) <= VEC3_DOT(b, b))
		return (true);
	return (false);
}

t_obj const		*nearest_intersect(t_vertex *dst, t_scene const *scene,
					t_vertex ray)
{
	t_obj const		*obj;
	uint32_t		i;
	t_obj const		*nearest;
	t_vertex		intersect;

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, 0.001f));
	nearest = NULL;
	i = 0;
	while (i < scene->objs.length)
	{
		obj = VGET(t_obj const*, scene->objs, i++);
		if (obj->type->ray_intersect(&intersect, obj, &ray) && (nearest == NULL
				|| is_nearest_than(&ray.pos, intersect.pos, dst->pos)))
		{
			nearest = obj;
			*dst = intersect;
		}
	}
	return (nearest);
}
