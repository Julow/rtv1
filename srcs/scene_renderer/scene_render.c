/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:31:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/07 13:14:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "color_utils.h"
#include "math_utils.h"
#include "ray_tracer.h"
#include "scene_render.h"

#include <math.h>

#define MAX_RAY_DEPTH		10

static t_vec3	get_view_plane(t_camera const *cam, t_vec2u size,
					t_vec3 *delta_x, t_vec3 *delta_y)
{
	t_vec3 const	right = ft_vec3norm(ft_vec3cross(cam->dir, VEC3_UP()));
	t_vec3 const	up = ft_vec3norm(ft_vec3cross(right, cam->dir));
	t_vec2			view_center;

	view_center.x = tanf(FOV / 2.f);
	view_center.y = ((float)size.y) / (float)size.x * view_center.x;
	*delta_x = VEC3_DIV1(VEC3_MUL1(right, 2 * view_center.x), size.x);
	*delta_y = VEC3_DIV1(VEC3_MUL1(up, 2 * view_center.y), size.y);
	return (VEC3_SUB(VEC3_SUB(
		VEC3_SUB(VEC3_ADD(cam->pos, cam->dir), VEC3_MUL1(up, view_center.y)),
		VEC3_MUL1(right, view_center.x)), cam->pos));
}

void			scene_render(t_img *dst, t_scene const *scene, uint32_t camera)
{
	t_camera const	*cam = VECTOR_GET(scene->cameras, camera);
	t_vec3			view_top;
	t_vec3			delta_x;
	t_vec3			delta_y;
	t_vec2u			pt;
	t_vertex		ray;

	view_top = get_view_plane(cam, VEC2U(dst->width, dst->height), &delta_x, &delta_y);
	ray.pos = cam->pos;
	pt.y = 0;
	while (pt.y < dst->height)
	{
		pt.x = 0;
		while (pt.x < dst->width)
		{
			ray.dir = ft_vec3norm(VEC3_ADD(VEC3_ADD(view_top, VEC3_MUL1(delta_x, pt.x)),
					VEC3_MUL1(delta_y, pt.y)));
			IMG_PIXEL(*dst, pt.x, pt.y) = color_fto24(
					ray_trace(scene, &ray, &scene->def_mtl, MAX_RAY_DEPTH));
			pt.x++;
		}
		pt.y++;
	}
}