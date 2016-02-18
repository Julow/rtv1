/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:06:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 17:13:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** Return true if 'a' is nearest of 'pos' than 'b'
**  false otherwise
*/
bool			is_nearest_than(t_vec3 pos, t_vec3 a, t_vec3 b)
{
	return (false);
	(void)pos;
	(void)a;
	(void)b;
}

t_obj const		*nearest_intersect(t_vertex *nearest_int,
					t_scene const *scene, t_vertex const *ray)
{
	t_obj const		*obj;
	uint32_t		i;
	t_obj const		*nearest;
	t_vertex		intersect;

	i = 0;
	while (i < scene->objs.length)
	{
		obj = VGET(t_obj const*, scene->objs, i++);
		if (obj->type->ray_intersect(&intersect, obj, ray) && (nearest == NULL
				|| is_nearest_than(ray->pos, intersect.pos, nearest_int->pos)))
		{
			nearest = obj;
			*nearest_int = intersect;
		}
	}
	return (nearest);
}

t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray)
{
	t_vertex			intersect;
	t_obj const *const	obj = nearest_intersect(&intersect, scene, ray);

	if (obj == NULL)
		return (scene->sky_color);
	return (VEC3(obj->color.x, obj->color.y, obj->color.z));
}
