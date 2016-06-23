/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:23:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/23 18:02:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

#include "math_utils.h"
#include "ray_tracer.h"
#include "scene_renderer.h"

// TODO: make it a config
#define MAX_RAY_DEPTH		10

void			scene_renderer_render(t_scene_renderer *renderer,
					t_vec2u pt, t_vec2u size)
{
	t_vec2u const	to = VEC2U_ADD(pt, size);
	t_vec2u			i;
	t_vertex		ray;

	ray.pos = renderer->camera->pos;
	i.y = pt.y;
	while (i.y < to.y)
	{
		i.x = pt.x;
		while (i.x < to.x)
		{
			ray.dir = ft_vec3norm(VEC3_ADD(
					VEC3_ADD(renderer->view_top, VEC3_MUL1(renderer->view_dx, i.x)),
					VEC3_MUL1(renderer->view_dy, i.y)));
			IMG_PIXEL(*renderer->dst, i.x, i.y) = color_fto24(colorf_gamma(
					ray_trace(renderer->scene, &ray, MAX_RAY_DEPTH),
					1.f / 2.2f));
			i.x++;
		}
		i.y++;
	}
}
