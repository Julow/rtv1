/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:04:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/27 18:08:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "ft/math_vec3.h"

# include "math_utils.h"
# include "obj.h"
# include "scene.h"

typedef struct s_ray_tracer			t_ray_tracer;

/*
** ========================================================================== **
** Ray tracer
*/

/*
** ray_tracer object
** scene			=> scene being render
** mat_stack		=> stack of material
** depth			=> used to avoid endless recursion
*/
struct			s_ray_tracer
{
	t_scene const	*scene;
	t_vector		mat_stack;
	uint32_t		depth;
};

/*
** Initialize a ray_tracer object
*/
void			ray_tracer_init(t_ray_tracer *dst, t_scene const *scene,
					t_vertex const *camera, uint32_t max_depth);

/*
** Throw a ray and compute it's target's color
** -
** The result color is not normalized
** -
** Store the result into 'result'
** Return false if the ray hit nothing, true otherwise
*/
bool			ray_trace(t_ray_tracer *t, t_vertex const *ray,
					t_vec3 *result);

/*
** Find the nearest intersect
** -
** dst->norm is not normalized (lol)
*/
t_obj const		*nearest_intersect(t_intersect *dst,
					t_scene const *scene, t_vertex ray);

#endif
