/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 17:03:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_sphere.h"

static bool		sphere_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray)
{
	// TODO
	(void)intersect;
	(void)obj;
	(void)ray;
	return (false);
}

t_obj			*sphere_new(void)
{
	static t_obj_class const	sphere_class = {
		SUBC("sphere"),
		&sphere_ray_intersect,
	};
	t_obj *const				sphere = NEW(t_obj);

	ft_bzero(sphere, sizeof(t_obj));
	sphere->type = &sphere_class;
	return (sphere);
}
