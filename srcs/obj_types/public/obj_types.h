/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/29 16:55:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_SPHERE_H
# define OBJ_SPHERE_H

# include "obj.h"

bool			sphere_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			plane_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			cylinder_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			cone_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);

bool			or_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			and_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			not_ray_intersect(t_intersect *intersect, t_obj const *obj,
					t_vertex const *ray);

#endif
