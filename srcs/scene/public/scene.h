/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/15 11:32:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/ft_dstr.h"
# include "ft/ft_vector.h"
# include "ft/math_vec3.h"

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

struct			s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	float			view_dist;
};

struct			s_scene
{
	t_dstr			name;
	t_vector		objs;
	t_vector		lights;
	t_vector		cameras;
	t_material		def_mtl;
	t_vec3			sky_color;
};

/*
** ========================================================================== **
** Default values
*/

# define DEF_CAMERA		((t_camera){VEC3_0(), VEC3(0.f, 0.f, 1.f), 1000.f})
# define DEF_MTL		((t_material){NULL, NULL, 0.01f, 1.f, 0.f, 1.f, 128.f})
# define DEF_TRANSFORM	(TRANSFORM(VEC3_0(), VEC3_0(), VEC3_0(), VEC3_1(1.f)))
# define DEF_LIGHT		((t_light){VEC3_0(), 1.f, VEC3_1(1.f), 1000.f, 4.f})
# define DEF_SKY_COLOR	(VEC3(0.f, 0.f, 0.f))

#endif
