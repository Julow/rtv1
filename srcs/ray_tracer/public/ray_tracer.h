/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:04:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 11:03:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "ft/math.h"

# include "math_utils.h"
# include "scene.h"

/*
** ========================================================================== **
** Ray tracer
*/

/*
** Throw a ray
** Return the color
*/
t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray);

/*
** Find the nearest intersect
*/
t_obj const		*nearest_intersect(t_vertex *dst,
					t_scene const *scene, t_vertex ray);

#endif
