/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/03/04 00:28:43 by juloo            ###   ########.fr       */
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

static void		obj_apply_transform(t_obj const *obj, t_vertex *v)
{
	ft_mat4apply_vec3(&obj->m, &v->pos);
#ifdef USE_QUATERNIONS
	// ft_quaternions_apply(&obj->rot, &v->dir);
	ft_quaternions_apply2(&obj->rot, &obj->rot_inv, &v->dir);
#else
	ft_mat4apply_vec3(&obj->rot_m, &v->dir);
#endif
}

static void		obj_reverse_transform(t_obj const *obj, t_vertex *v)
{
	ft_mat4apply_vec3(&obj->m_inv, &v->pos);
#ifdef USE_QUATERNIONS
	// ft_quaternions_reverse(&obj->rot, &v->dir);
	ft_quaternions_apply2(&obj->rot_inv, &obj->rot, &v->dir);
#else
	ft_mat4apply_vec3(&obj->rot_m_inv, &v->dir);
#endif
}

t_obj const		*nearest_intersect(t_vertex *dst, t_scene const *scene,
					t_vertex ray)
{
	t_obj const		*obj;
	uint32_t		i;
	t_obj const		*nearest;
	t_vertex		intersect;
	t_vertex		tmp;

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, 0.01f));
	nearest = NULL;
	i = 0;
	while (i < scene->objs.length)
	{
		obj = VECTOR_GET(scene->objs, i++);
		tmp = ray;
		obj_reverse_transform(obj, &tmp);
		if (obj->type->ray_intersect(&intersect, obj, &tmp))
		{
			obj_apply_transform(obj, &intersect);
			if (nearest == NULL
				|| is_nearest_than(&ray.pos, intersect.pos, dst->pos))
			{
				nearest = obj;
				*dst = intersect;
			}
		}
	}
	return (nearest);
}
