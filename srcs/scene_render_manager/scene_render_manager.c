/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 15:44:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 18:16:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_render_manager.h"

void			scene_render_manager(t_scene_render_manager *m, t_vec2u chunk_size,
					t_scene const *scene, uint32_t camera, t_img *dst)
{
	m->_ = TASK_MANAGER(&render_task_init, sizeof(t_render_task));
	scene_renderer_init(&m->renderer, scene, camera, dst);
	m->chunk_size = chunk_size;
	m->progress = VEC2U1(0);
}
