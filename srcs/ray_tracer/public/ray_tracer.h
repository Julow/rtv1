/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:04:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/02 17:57:32 by jaguillo         ###   ########.fr       */
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

/*
** TMP
*/
struct			s_ray_stats
{
	uint32_t	light_ray;
	uint32_t	render_ray;
	uint32_t	sky_ray;
	uint32_t	intersect_search;
	uint32_t	intersect_test;
};

extern struct s_ray_stats	g_ray_stats;

#endif
