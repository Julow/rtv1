/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/04/17 14:57:01 by juloo            ###   ########.fr       */
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
typedef bool					(*t_intersect_f)(t_intersect *intersect,
									t_obj const *obj, t_vertex const *ray);

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
** Object
*/
struct			s_obj
{
	struct {
		t_intersect_f	ray_intersect;
	}				type[1];
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
