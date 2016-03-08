/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/08 23:20:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/libft.h"
# include "ft/math.h"

# include "math_utils.h"

typedef struct s_obj			t_obj;
typedef struct s_obj_class		t_obj_class;
typedef struct s_material		t_material;

/*
** ========================================================================== **
** Obj
*/

# define INTERSECT_ERROR		0.0001f

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
	t_vec3				pos;
	t_mat4				m;
	t_mat4				m_inv;
};

#endif
