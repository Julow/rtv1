/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/20 23:13:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/ft_dstr.h"
# include "ft/ft_vector.h"
# include "ft/math.h"

# include "obj.h"

typedef struct s_scene			t_scene;
typedef struct s_light			t_light;

/*
** ========================================================================== **
** Scene
*/

struct			s_light
{
	t_vec3			pos;
	float			light;
	t_vec3			color;
};

struct			s_scene
{
	t_dstr			name;
	t_vector		objs;
	t_vector		lights;
	t_material		def_mtl;
	t_vec3			sky_color;
};

#endif
