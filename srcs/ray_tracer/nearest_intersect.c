/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/03/18 18:01:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"

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

typedef struct s_nearest		t_nearest;

struct			s_nearest
{
	t_intersect		intersect;
	t_obj const		*obj;
};

static bool		obj_intersect(t_nearest *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_vertex		tmp;
	t_intersect		intersect;

	tmp = *ray;
	ft_mat4apply_vec3(&obj->m_inv, &tmp.pos, 1.f);
	ft_mat4apply_vec3(&obj->m_inv, &tmp.dir, 0.f);
	if (obj->type->ray_intersect(&intersect, obj, &tmp))
	{
		ft_mat4apply_vec3(&obj->m, &intersect.pos, 1.f);
		ft_mat4apply_vec3(&obj->m, &intersect.norm, 0.f);
		if (dst->obj == NULL
			|| is_nearest_than(&ray->pos, intersect.pos, dst->intersect.pos))
		{
			dst->obj = obj;
			dst->intersect = intersect;
		}
		return (true);
	}
	return (false);
}

t_obj const		*nearest_intersect(t_intersect *dst, t_scene const *scene,
					t_vertex ray)
{
	t_nearest		nearest;

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, 0.01f));
	nearest.obj = NULL;
	if (!kdtree_intersect(&scene->objs, (float*)&ray,
			CALLBACK(obj_intersect, &nearest)))
		return (NULL);
	*dst = nearest.intersect;
	return (nearest.obj);
}
