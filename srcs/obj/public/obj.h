/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/29 09:06:04 by jaguillo         ###   ########.fr       */
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

/*
** ========================================================================== **
** Obj
*/

# define INTERSECT_ERROR		0.00001f

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
	bool			(*ray_intersect)(t_intersect *intersect, t_obj const *obj,
						t_vertex const *ray);
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
