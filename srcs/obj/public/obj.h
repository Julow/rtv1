/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/22 12:30:42 by juloo            ###   ########.fr       */
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
typedef struct s_transform		t_transform;

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
};

# define MATERIAL(R,G,B,...)	((t_material){.color=VEC3(R,G,B),##__VA_ARGS__})

/*
** Transform
*/
struct			s_transform
{
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	t_vec3			scale;
};

# define TRANSFORM(P,R,H,S)		((t_transform){(P), (R), (H), (S)})

void			transform_matrix(t_transform const *t, t_mat4 *m, t_mat4 *m_inv);

/*
** Object
*/
struct			s_obj
{
	t_obj_class const	*type;
	t_material			material;
	t_mat4				m;
	t_mat4				m_inv;
};

#endif
