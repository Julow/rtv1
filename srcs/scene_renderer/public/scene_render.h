/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:29:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 15:41:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_RENDER_H
# define SCENE_RENDER_H

# include "ft/img.h"
# include "scene.h"

# define FOV		42.f

/*
** ========================================================================== **
** Render a scene
*/

void			scene_render(t_img *dst, t_scene const *scene, uint32_t camera);

#endif
