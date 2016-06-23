/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/23 17:04:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_renderer.h"
#include <math.h>

// TODO: make it a config
#define FOV		42.f

static void		load_view_plane(t_scene_renderer *r,
					t_camera const *cam, t_vec2u size)
{
	t_vec3 const	right = ft_vec3norm(ft_vec3cross(cam->dir, VEC3_UP()));
	t_vec3 const	up = ft_vec3norm(ft_vec3cross(right, cam->dir));
	t_vec2			view_center;

	view_center.x = tanf(FOV / 2.f);
	view_center.y = ((float)size.y) / (float)size.x * view_center.x;
	r->view_top = VEC3_SUB(VEC3_SUB(
		VEC3_SUB(VEC3_ADD(cam->pos, cam->dir), VEC3_MUL1(up, view_center.y)),
		VEC3_MUL1(right, view_center.x)), cam->pos);
	r->view_dx = VEC3_DIV1(VEC3_MUL1(right, 2 * view_center.x), size.x);
	r->view_dy = VEC3_DIV1(VEC3_MUL1(up, 2 * view_center.y), size.y);
}

void			scene_renderer_init(t_scene_renderer *r,
					t_scene const *scene, uint32_t camera, t_img *dst)
{
	r->scene = scene;
	r->camera = VECTOR_GET(scene->cameras, camera);
	r->dst = dst;
	load_view_plane(r, r->camera, VEC2U(dst->width, dst->height));
}
