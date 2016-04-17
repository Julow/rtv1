/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/04/17 14:47:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/ft_vector.h"
# include "ft/math_vec3.h"

# include "kd_tree.h"
# include "obj.h"

typedef struct s_scene			t_scene;
typedef struct s_light			t_light;
typedef struct s_camera			t_camera;

/*
** ========================================================================== **
** Scene
*/

struct			s_light
{
	t_vec3			pos;
	float			brightness;
	t_vec3			color;
	float			att_dist;
	float			att_exp;
};

# define DEF_LIGHT		((t_light){VEC3_0(), 1.f, VEC3_1(1.f), 1000.f, 4.f})

struct			s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	float			view_dist;
};

# define DEF_CAMERA		((t_camera){VEC3_0(), VEC3(0.f, 0.f, 1.f), 1000.f})

struct			s_scene
{
	t_sub			name;
	t_kdtree		objs;
	t_vector		lights;
	t_vector		cameras;
	t_vec3			sky_color;
};

# define DEF_SKY_COLOR	(VEC3(0.f, 0.f, 0.f))

#endif
