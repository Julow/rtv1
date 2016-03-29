/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:57:46 by juloo             #+#    #+#             */
/*   Updated: 2016/03/29 13:27:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"

#define RAY_ERROR		0.01f

typedef struct s_nearest		t_nearest;

struct			s_nearest
{
	t_intersect		intersect;
	t_obj const		*obj;
};

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

// static bool		csg_intersect(t_intersect *dst, t_obj const *obj,
// 					t_vertex const *ray)
// {
// 	t_intersect		intrsct[2];
// 	bool			b[2];

// 	if (obj->csg == NULL)
// 		return (ray_intersect(dst, obj, ray));
// 	b[0] = ray_intersect(&intrsct[0], obj, ray);
// 	b[1] = ray_intersect(&intrsct[1], obj->csg->obj, ray);
// 	if (obj->csg->type == OBJ_CSG_OR)
// 	{
// 		if (b[0])
// 			*dst = intrsct[(b[1] && intrsct[0].dist > intrsct[1].dist) ? 1 : 0];
// 		else if (b[1])
// 			*dst = intrsct[1];
// 		else
// 			return (false);
// 	}
// 	else if (obj->csg->type == OBJ_CSG_NOT)
// 	{
// 		if (!b[0])
// 			return (false);
// 		t_vertex		tmp;

// 		while (b[1] && intrsct[1].dist <= intrsct[0].dist)
// 		{
// 			tmp.pos = VEC3_ADD(intrsct[1].pos, VEC3_MUL1(ray->dir, RAY_ERROR));
// 			tmp.dir = ray->dir;
// 			b[1] = ray_intersect(&intrsct[1], obj->csg->obj, &tmp);
// 		}
// 		*dst = b[1] ? intrsct[1] : intrsct[0];
// 	}
// 	else if (obj->csg->type == OBJ_CSG_AND)
// 	{
// 		if (!b[0] || !b[1])
// 			return (false);
// 		*dst = intrsct[(intrsct[0].dist > intrsct[1].dist) ? 0 : 1];
// 	}
// 	return (true);
// }

static bool		obj_intersect(t_nearest *dst, t_obj const *obj,
					t_vertex const *ray)
{
	t_intersect		intersect;

	if (ray_intersect(&intersect, obj, ray))
	{
		if (dst->obj == NULL || intersect.dist < dst->intersect.dist)
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

	ray.pos = VEC3_ADD(ray.pos, VEC3_MUL1(ray.dir, RAY_ERROR));
	nearest.obj = NULL;
	if (!kdtree_intersect(&scene->objs, (float*)&ray,
			CALLBACK(obj_intersect, &nearest)))
		return (NULL);
	*dst = nearest.intersect;
	return (nearest.obj);
}
