/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 18:09:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/27 18:12:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void			ray_tracer_init(t_ray_tracer *dst, t_scene const *scene,
					t_vertex const *camera, uint32_t max_depth)
{
	dst->scene = scene;
	dst->mat_stack = VECTOR(t_material const*);
	dst->depth = max_depth;
	(void)camera; // TODO: compute mat_stack
}
