/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/06/25 01:44:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"

static bool		obj_intersect(t_nearest *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_intersect		intersect;
	t_vertex		tmp_ray;

	tmp_ray = *ray;
	ft_mat4apply_vec3(&obj->m_inv, &tmp_ray.pos, 1.f);
	ft_mat4apply_vec3(&obj->m_inv, &tmp_ray.dir, 0.f);
	if (obj->type->ray_intersect(obj, &tmp_ray, false, &intersect))
	{
		if (dst->obj == NULL || intersect.dist < dst->intersect.dist)
		{
			ft_mat4apply_vec3(&obj->m, &intersect.pos, 1.f);
			ft_mat4apply_vec3(&obj->m, &intersect.norm, 0.f);
			*dst = (t_nearest){intersect, obj};
		}
		return (true);
	}
	return (false);
}

t_obj const		*nearest_intersect(t_intersect *dst, t_scene const *scene,
					t_vertex ray)
{
	t_nearest		nearest;

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, RAY_ERROR));
	nearest.obj = NULL;
	if (!kdtree_intersect(&scene->objs, (float*)&ray,
			CALLBACK(obj_intersect, &nearest)))
		return (NULL);
	*dst = nearest.intersect;
	return (nearest.obj);
}
