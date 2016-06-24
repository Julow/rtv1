/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render_manager.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 13:09:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 17:48:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_RENDER_MANAGER_H
# define SCENE_RENDER_MANAGER_H

# include "ft/libft.h"
# include "ft/thread_pool.h"

# include "scene_renderer.h"

typedef struct s_scene_render_manager	t_scene_render_manager;

/*
** ========================================================================== **
** Managed scene_renderer to use with a thread pool
*/

struct			s_scene_render_manager
{
	t_task_manager		_;
	t_scene_renderer	renderer;
	t_vec2u				chunk_size;
	t_vec2u				progress;
};

void			scene_render_manager(t_scene_render_manager *m, t_vec2u chunk_size,
					t_scene const *scene, uint32_t camera, t_img *dst);

#endif
