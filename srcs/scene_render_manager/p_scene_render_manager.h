/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_scene_render_manager.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 15:46:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 17:49:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SCENE_RENDER_MANAGER_H
# define P_SCENE_RENDER_MANAGER_H

# include "ft/thread_pool.h"
# include "scene_render_manager.h"

typedef struct s_render_task		t_render_task;

/*
** ========================================================================== **
*/

struct			s_render_task
{
	t_scene_renderer	*renderer;
	t_vec2u				pt;
	t_vec2u				size;
};

bool			render_task_init(t_scene_render_manager *m,
					t_task_f *f, t_render_task *task);

#endif
