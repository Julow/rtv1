/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:13:06 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 18:16:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "obj_types.h"

bool			sphere_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			plane_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray);
bool			cylinder_ray_intersect(t_vertex *intersect, t_obj const *obj,
					t_vertex const *ray);

#endif
