/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:23:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/28 16:08:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

#include "math_utils.h"
#include "ray_tracer.h"
#include "scene_renderer.h"

// TODO: make it a config
#define MAX_RAY_DEPTH		10

static t_vec3	normalize_color(t_vec3 color)
{
	float const		max = MAX(MAX(color.x, color.y), color.z);

	if (max > 1.f) // TODO: do it after rendering
		color = VEC3_DIV1(color, max);
	return (colorf_gamma(color, 1.f / 2.2f));
}

void			scene_renderer_render(t_scene_renderer *renderer,
					t_vec2u pt, t_vec2u size)
{
	t_vec2u const	to = VEC2U_ADD(pt, size);
	t_vec2u			i;
	t_vertex		ray;
	t_vec3			color;
	t_ray_tracer	ray_tracer;

	ray.pos = renderer->camera->pos;
	ray.dir = renderer->camera->dir;
	ray_tracer_init(&ray_tracer, renderer->scene, &ray, MAX_RAY_DEPTH);
	i.y = pt.y;
	while (i.y < to.y)
	{
		i.x = pt.x;
		while (i.x < to.x)
		{
			ray.dir = ft_vec3norm(VEC3_ADD(
					VEC3_ADD(renderer->view_top, VEC3_MUL1(renderer->view_dx, i.x)),
					VEC3_MUL1(renderer->view_dy, i.y)));
			if (!ray_trace(&ray_tracer, &ray, &color))
				color = renderer->scene->sky_color;
			color = normalize_color(color);
			IMG_PIXEL(*renderer->dst, i.x, i.y) = color_fto24(color);
			i.x++;
		}
		i.y++;
	}
}
