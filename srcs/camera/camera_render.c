/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:31:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 21:05:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "camera.h"
#include "math_utils.h"
#include "ray_tracer.h"

static uint32_t	color_fto24(t_vec3 color)
{
	return (
		  (((uint8_t)(color.x * 255.f)) << 16)
		| (((uint8_t)(color.y * 255.f)) << 8)
		| (((uint8_t)(color.z * 255.f)) << 0)
	);
}

static uint32_t	color_fto32(t_vec4 color)
{
	return (
		  (((uint8_t)(color.w * 255.f)) << 24)
		| (((uint8_t)(color.x * 255.f)) << 16)
		| (((uint8_t)(color.y * 255.f)) << 8)
		| (((uint8_t)(color.z * 255.f)) << 0)
	);
}

void			camera_render(t_img *dst, t_camera const *camera,
					t_scene const *scene)
{
	t_vec3			viewPlane;
	t_vec2u			pt;
	t_vertex		ray;

	viewPlane = VEC3_SUB(VEC3_ADD(camera->pos,
			VEC3_ADD(
				VEC3_MUL1(camera->dir, camera->plane_dist),
				VEC3_MUL1(VEC3(0.f, 1.f, 0.f), dst->height / 2.f)
			))
		, VEC3_MUL1(VEC3(1.f, 0.f, 0.f), dst->width / 2.f));
	pt = VEC2U(0, 0);
	ray = VERTEX(camera->pos, VEC3_0());
	ray.dir.z = viewPlane.z;
	while (pt.y < dst->height)
	{
		pt.x = 0;
		while (pt.x < dst->width)
		{
			ray.dir.x = viewPlane.x + pt.x;
			ray.dir.y = viewPlane.y - pt.y;
			IMG_PIXEL(*dst, pt.x, pt.y) = color_fto24(ray_trace(scene, &ray));
			pt.x++;
		}
		pt.y++;
	}
}
