/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 18:52:57 by jaguillo         ###   ########.fr       */
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
typedef struct s_material		t_material;
typedef struct s_intersect		t_intersect;
typedef struct s_obj_type		t_obj_type;

/*
** Intersection function
** -
** if 'both' is true, 2 intersections are store into 'intersect'
** otherwise, the min positive intersection is used
*/
typedef bool					(*t_intersect_f)(t_obj const *obj,
									t_vertex const *ray, bool both,
									t_intersect *intersect);

/*
** ========================================================================== **
** Obj
*/

# define INTERSECT_ERROR		0.00001f
# define RAY_ERROR				0.001f

/*
** Material
*/
struct			s_material
{
	t_img const		*texture;
	t_img const		*specular_map;
	t_img const		*normal_map;
	float			ambient;
	float			reflection;
	float			refract_index;
	float			specular_exp;
};

# define DEF_MTL		((t_material){NULL, NULL, NULL, 0.01f, 0.f, 1.f, 128.f})

/*
** Obj type
*/
struct			s_obj_type
{
	t_intersect_f	ray_intersect;
};

/*
** Object
*/
struct			s_obj
{
	t_obj_type		type[1];
	t_material		material;
	t_mat4			m;
	t_mat4			m_inv;
};

/*
** Intersection
*/
struct			s_intersect
{
	t_vec3			pos;
	t_vec3			norm;
	t_vec2			tex;
	float			dist;
};

#endif
