/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 18:28:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_TYPES_H
# define OBJ_TYPES_H

# include "obj.h"

/*
** TODO: return obj instead of bool
*/

bool			sphere_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);
bool			plane_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);
bool			cylinder_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);
bool			cone_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);

bool			or_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);
bool			and_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);
bool			not_ray_intersect(t_obj const *obj, t_vertex const *ray,
					bool both, t_intersect *intersect);

#endif
