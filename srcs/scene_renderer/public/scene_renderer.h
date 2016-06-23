/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_renderer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:14:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/23 17:03:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_RENDERER_H
# define SCENE_RENDERER_H

# include "ft/img.h"
# include "ft/libft.h"
# include "ft/math_vec3.h"

# include "scene.h"

typedef struct s_scene_renderer			t_scene_renderer;

/*
** ========================================================================== **
*/

struct			s_scene_renderer
{
	t_scene const	*scene;
	t_camera const	*camera;
	t_vec3			view_top;
	t_vec3			view_dx;
	t_vec3			view_dy;
	t_img			*dst;
};

/*
** Initialize a scene_renderer
*/
void			scene_renderer_init(t_scene_renderer *r,
					t_scene const *scene, uint32_t camera, t_img *dst);

/*
** Render a part of the scene
** the 'pt'/'size' rect must fit into the 'dst' image
*/
void			scene_renderer_render(t_scene_renderer *renderer,
					t_vec2u pt, t_vec2u size);

#endif
