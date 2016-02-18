/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 17:10:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/libft.h"
# include "ft/math.h"

# include "math_utils.h"

typedef struct s_transform		t_transform;

typedef struct s_obj			t_obj;
typedef struct s_obj_class		t_obj_class;

/*
** ========================================================================== **
** Obj
*/

/*
** Transformations
*/
struct			s_transform
{
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	t_vec3			scale;
	t_mat4			_matrix;
	t_mat4			_matrix_inv;
};

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
** Object
*/
struct			s_obj
{
	t_obj_class const	*type;
	t_transform			transform;
	t_vec4				color;
	float				refract_index;
};

#endif
