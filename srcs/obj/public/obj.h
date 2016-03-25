/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/25 17:12:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/img.h"
# include "ft/libft.h"
# include "ft/math_mat4.h"
# include "ft/math_vec2.h"
# include "ft/math_vec3.h"

# include "math_utils.h"

typedef struct s_obj			t_obj;
typedef struct s_obj_class		t_obj_class;
typedef struct s_material		t_material;
typedef struct s_intersect		t_intersect;

/*
** ========================================================================== **
** Obj
*/

# define INTERSECT_ERROR		0.00001f

/*
** Represent an object type
** 'ray_intersect' have to find the intersection between 'ray' and 'obj'
**   or to return false if there is no intersection
*/
struct			s_obj_class
{
	t_sub			name;
	bool			(*ray_intersect)(t_intersect *intersect, t_obj const *obj,
						t_vertex const *ray);
	t_vec3 const	*bounds;
	uint32_t		bounds_len;
};

/*
** Material
*/
struct			s_material
{
	t_img const		*texture;
	t_img const		*specular_map;
	float			ambient;
	float			reflection;
	float			refract_index;
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
};

/*
** Intersection
*/
struct			s_intersect
{
	t_vec3			pos;
	t_vec3			norm;
	t_vec2			tex;
};

#endif
