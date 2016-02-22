/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/22 22:04:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/math.h"

typedef struct s_vertex		t_vertex;

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

# define VEC3_DOT(A, B)		(((A).x*(B).x)+((A).y*(B).y)+((A).z*(B).z))

# define VEC4_DOT(A, B)		((A).x*(B).x+(A).y*(B).y+(A).z*(B).z+(A).w*(B).w)

# define VEC3_1(A)			(VEC3(A, A, A))

float			ft_vec3length(t_vec3 v);

float			ft_vec3dist(t_vec3 a, t_vec3 b);
float			ft_vec3dist2(t_vec3 a, t_vec3 b);

t_vec3			ft_vec3mix(t_vec3 a, t_vec3 b, float mix);

void			ft_mat4apply_vertex(t_mat4 const *m, t_vertex *v);
void			ft_mat4apply_vec3(t_mat4 const *m, t_vec3 *v);
void			ft_mat4apply_vec4(t_mat4 const *m, t_vec4 *v);

#endif
