/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 14:03:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_SPHERE_H
# define OBJ_SPHERE_H

# include "obj.h"

typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;

/*
** ========================================================================== **
** Sphere
*/

struct			s_sphere
{
	t_obj			obj;
	t_vec3			pos;
	float			radius;
};

t_sphere		*sphere_new(void);

/*
** ========================================================================== **
** Plane
*/

struct			s_plane
{
	t_obj			obj;
	t_vec3			norm;
	float			offset;
};

t_plane			*plane_new(void);

#endif
