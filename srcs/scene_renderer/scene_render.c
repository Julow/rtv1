/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:31:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/24 19:31:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "color_utils.h"
#include "math_utils.h"
#include "ray_tracer.h"
#include "scene_render.h"

#define MAX_RAY_DEPTH		10

void			scene_render(t_img *dst, t_scene const *scene, uint32_t camera)
{
	t_camera const	*cam = VECTOR_GET(scene->cameras, camera);
	t_vec3			viewPlane;
	t_vec2u			pt;
	t_vertex		ray;

	viewPlane = VEC3_SUB(VEC3_ADD(cam->pos,
			VEC3_ADD(
				VEC3_MUL1(cam->dir, cam->view_dist),
				VEC3_MUL1(VEC3(0.f, 1.f, 0.f), dst->height / 2.f)
			))
		, VEC3_MUL1(VEC3(1.f, 0.f, 0.f), dst->width / 2.f));
	pt = VEC2U(0, 0);
	ray = VERTEX(cam->pos, VEC3_0());
	ray.dir.z = viewPlane.z;
	while (pt.y < dst->height)
	{
		pt.x = 0;
		while (pt.x < dst->width)
		{
			ray.dir.x = viewPlane.x + pt.x;
			ray.dir.y = viewPlane.y - pt.y;
			IMG_PIXEL(*dst, pt.x, pt.y) = color_fto24(
					ray_trace(scene, &ray, &scene->def_mtl, MAX_RAY_DEPTH));
			pt.x++;
		}
		pt.y++;
	}
}
