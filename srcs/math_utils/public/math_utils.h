/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/23 00:11:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/libft.h"
# include "ft/math_vec3.h"

typedef struct s_vertex			t_vertex;

/*
** ========================================================================== **
** Math utils
** -
** MIX(A, B, RATIO+)	Return the value at RATIO between A and B
** DIFF(A+, B+)			Return abs(A - B) (allow unsigned)
** IS_POSITIVE(A)		Return true if A is positive, false otherwise
*/

# define MIX(A, B, RATIO)	((A) * (RATIO) + ((B) * (1.f - (RATIO))))

# define DIFF(A, B)			(((A) > (B)) ? (A) - (B) : (B) - (A))

# define IS_POSITIVE(A)		(((A) < 0) ? false : true)

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

#endif
