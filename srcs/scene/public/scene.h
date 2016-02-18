/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 16:34:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/ft_vector.h"
# include "ft/math.h"

# include "obj.h"

typedef struct s_scene			t_scene;

/*
** ========================================================================== **
** Scene
*/

struct			s_scene
{
	t_vector		objs;
	t_vec3			sky_color;
};

#endif
