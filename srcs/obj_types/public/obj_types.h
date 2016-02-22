/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/22 22:26:36 by juloo            ###   ########.fr       */
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
};

t_sphere		*sphere_new(void);

/*
** ========================================================================== **
** Plane
*/

struct			s_plane
{
	t_obj			obj;
};

t_plane			*plane_new(void);

#endif
