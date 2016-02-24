/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:29:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/24 19:31:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft/img.h"
# include "scene.h"

/*
** ========================================================================== **
** Render a scene
*/

void			scene_render(t_img *dst, t_scene const *scene, uint32_t camera);

#endif
