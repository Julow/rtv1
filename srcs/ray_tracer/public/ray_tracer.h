/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:04:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/27 13:03:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "ft/math_vec3.h"

# include "math_utils.h"
# include "obj.h"
# include "scene.h"

/*
** ========================================================================== **
** Ray tracer
*/

/*
** Throw a ray
** Return the color
*/
t_vec3			ray_trace(t_scene const *scene, t_vertex const *ray,
					uint32_t max_depth);

/*
** Find the nearest intersect
** -
** dst->norm is not normalized (lol)
*/
t_obj const		*nearest_intersect(t_intersect *dst,
					t_scene const *scene, t_vertex ray);

#endif
