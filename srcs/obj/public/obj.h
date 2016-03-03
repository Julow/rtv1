/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/04 00:28:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/libft.h"
# include "ft/math.h"

# define USE_QUATERNIONS

# include "math_utils.h"

# ifdef USE_QUATERNIONS

#  include "math_quaternions.h"

# endif

typedef struct s_obj			t_obj;
typedef struct s_obj_class		t_obj_class;
typedef struct s_material		t_material;

/*
** ========================================================================== **
** Obj
*/

/*
** Represent an object type
** 'ray_intersect' have to find the intersection between 'ray' and 'obj'
**   or to return false if there is no intersection
*/
struct			s_obj_class
{
	t_sub			name;
	bool			(*ray_intersect)(t_vertex *intersect, t_obj const *obj,
						t_vertex const *ray);
};

/*
** Material
*/
struct			s_material
{
	t_vec3			color;
	float			opacity;
	float			reflection;
	float			refract_index;
	t_vec3			specular_color;
	float			specular_exp;
};

# define MATERIAL(R,G,B,...)	((t_material){.color=VEC3(R,G,B),##__VA_ARGS__})

/*
** Object
*/
struct			s_obj
{
	t_obj_class const	*type;
	t_material			material;
	t_mat4				m;
	t_mat4				m_inv;
# ifdef USE_QUATERNIONS
	t_quaternions		rot;
	t_quaternions		rot_inv;
# else
	t_mat4				rot_m;
	t_mat4				rot_m_inv;
# endif
};

#endif
