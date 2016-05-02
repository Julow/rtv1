/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/05/02 17:56:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"

typedef struct s_nearest		t_nearest;

struct			s_nearest
{
	t_intersect		intersect;
	t_obj const		*obj;
};

static bool		obj_intersect(t_nearest *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_intersect		intersect;
	t_vertex		tmp;

	g_ray_stats.intersect_test++;
	tmp = *ray;
	ft_mat4apply_vec3(&obj->m_inv, &tmp.pos, 1.f);
	ft_mat4apply_vec3(&obj->m_inv, &tmp.dir, 0.f);
	if (obj->type->ray_intersect(&intersect, obj, &tmp))
	{
		if (dst->obj == NULL || intersect.dist < dst->intersect.dist) // TODO: wrong ??
		{
			ft_mat4apply_vec3(&obj->m, &intersect.pos, 1.f);
			ft_mat4apply_vec3(&obj->m, &intersect.norm, 0.f);
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

	g_ray_stats.intersect_search++;
	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, RAY_ERROR));
	nearest.obj = NULL;
	if (!kdtree_intersect(&scene->objs, (float*)&ray,
			CALLBACK(obj_intersect, &nearest)))
		return (NULL);
	*dst = nearest.intersect;
	return (nearest.obj);
}
