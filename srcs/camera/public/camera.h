/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:29:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 17:35:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft/img.h"
# include "ft/math.h"

# include "scene.h"

typedef struct s_camera		t_camera;

/*
** ========================================================================== **
** Camera
*/

struct			s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	float			plane_dist;
};

void			camera_render(t_img *dst, t_camera const *camera,
					t_scene const *scene);

#endif
