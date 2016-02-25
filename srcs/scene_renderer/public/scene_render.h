/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:29:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/25 19:21:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft/img.h"
# include "scene.h"

#define FOV		42.f

/*
** ========================================================================== **
** Render a scene
*/

void			scene_render(t_img *dst, t_scene const *scene, uint32_t camera);

#endif
