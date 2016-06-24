/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_task.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 15:48:38 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 17:59:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_render_manager.h"

static void		render_task(t_render_task *task)
{
	scene_renderer_render(task->renderer, task->pt, task->size);
}

bool			render_task_init(t_scene_render_manager *m,
					t_task_f *f, t_render_task *task)
{
	if (m->progress.x >= m->renderer.dst->width)
	{
		m->progress.x = 0;
		m->progress.y += m->chunk_size.y;
	}
	if (m->progress.y >= m->renderer.dst->height)
		return (false);
	*f = V(&render_task);
	task->renderer = &m->renderer;
	task->pt = m->progress;
	task->size = VEC2U(
		MIN(m->chunk_size.x, m->renderer.dst->width - m->progress.x),
		MIN(m->chunk_size.y, m->renderer.dst->height - m->progress.y));
	m->progress.x += m->chunk_size.x;
	return (true);
}
