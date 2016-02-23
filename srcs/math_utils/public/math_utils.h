/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/23 17:53:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/libft.h"
# include "ft/math.h"

typedef struct s_vertex		t_vertex;
typedef struct s_transform		t_transform;

/*
** ========================================================================== **
** Vertex
*/

struct			s_vertex
{
	t_vec3			pos;
	t_vec3			dir;
};

# define VERTEX(POS, DIR)	((t_vertex){(POS), (DIR)})

# define VERTEX_A(V)		((V).pos)
# define VERTEX_B(V)		(VEC3_ADD((V).pos, (V).dir))
# define VERTEX_AB(A, B)	(VERTEX(A, VEC3_SUB(B, A)))

/*
** ========================================================================== **
*/

# define VEC2_DOT(A, B)		(((A).x*(B).x)+((A).y*(B).y))
# define VEC3_DOT(A, B)		(((A).x*(B).x)+((A).y*(B).y)+((A).z*(B).z))
# define VEC4_DOT(A, B)		((A).x*(B).x+(A).y*(B).y+(A).z*(B).z+(A).w*(B).w)

# define VEC3_1(A)			(VEC3(A, A, A))

# define VEC3_X(V,X)		(VEC3((X), (V).y, (V).z))
# define VEC3_Y(V,Y)		(VEC3((V).x, (Y), (V).z))
# define VEC3_Z(V,Z)		(VEC3((V).x, (V).y, (Z)))

float			ft_vec3length(t_vec3 v);

float			ft_vec3dist(t_vec3 a, t_vec3 b);
float			ft_vec3dist2(t_vec3 a, t_vec3 b);

t_vec3			ft_vec3mix(t_vec3 a, t_vec3 b, float mix);

void			ft_mat4apply_vertex(t_mat4 const *m, t_vertex *v);
void			ft_mat4apply_vec3(t_mat4 const *m, t_vec3 *v);
void			ft_mat4apply_vec4(t_mat4 const *m, t_vec4 *v);

/*
** ========================================================================== **
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

#endif
