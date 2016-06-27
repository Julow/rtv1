/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/27 19:13:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/libft.h"
# include "ft/math_vec3.h"

typedef struct s_vertex			t_vertex;

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
** Vec2u
*/

# define VEC2U_ADD(A, B)	(_VEC2U_OP(A, +, B))
# define VEC2U_SUB(A, B)	(_VEC2U_OP(A, -, B))

# define _VEC2U_OP(A,OP,B)	(VEC2U((A).x OP (B).x, (A).y OP (B).y))

/*
** ========================================================================== **
** Vec3
*/

# define VEC3_LERP(A, B, T)		(VEC3_ADD(VEC3_MUL1(A,1.f-(T)),VEC3_MUL1(B,T)))

#endif
