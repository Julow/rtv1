/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_quaternions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 22:32:35 by juloo             #+#    #+#             */
/*   Updated: 2016/03/01 18:54:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_QUATERNIONS_H
# define MATH_QUATERNIONS_H

# include "ft/math.h"
# include "math_utils.h"

typedef struct s_quaternions	t_quaternions;

/*
** ========================================================================== **
** Quaternions
** -
** QUATERNIONS(S, V)		t_quaternions constructor {S, V}
** QUATERNIONS_I()			t_quaternions constructor {1, 0}
** QUATERNIONS_0()			t_quaternions constructor {0, 0}
** -
** QUATERNIONS_ADD(A+, B+)	t_quaternions A + t_quaternions B
** QUATERNIONS_SUB(A+, B+)	t_quaternions A - t_quaternions B
** QUATERNIONS_MUL(A+, B+)	t_quaternions A * t_quaternions B
** -
** QUATERNIONS_MUL1(A+, B+)	t_quaternions A * float B
** QUATERNIONS_DIV1(A+, B+)	t_quaternions A / float B
** -
** ft_quaternions_length	Return the length of a t_quaternions
** ft_quaternions_norm		Normalize a t_quaternions
** ft_quaternions_inv		Return the inverse of a t_quaternions
** ft_quaternions_apply		Apply a t_quaternions to a t_vec3
** ft_quaternions_reverse	Apply the inverse of a t_quaternions to a t_vec3
** ft_quaternions_rot		Return the quaternions of a rotation
*/

struct			s_quaternions
{
	float			s;
	t_vec3			v;
};

# define QUATERNIONS(S, V)		((t_quaternions){(S), (V)})
# define QUATERNIONS_I()		((t_quaternions){(1.f), VEC3_0()})
# define QUATERNIONS_0()		((t_quaternions){(0.f), VEC3_0()})

# define QUATERNIONS_ADD(A, B)	(QUATERNIONS((A).s+(B).s,VEC3_ADD((A).v,(B).v)))
# define QUATERNIONS_SUB(A, B)	(QUATERNIONS((A).s-(B).s,VEC3_SUB((A).v,(B).v)))

# define QUATERNIONS_MUL(A, B)	(QUATERNIONS(								\
					(A).s*(B).s - VEC3_DOT((A).v, (B).v),					\
					VEC3_ADD(VEC3_ADD(VEC3_MUL1((B).v, (A).s),				\
						VEC3_MUL1((A).v, (B).s)), VEC3_CROSS((A).v, (B).v))	\
				))

# define QUATERNIONS_MUL1(A, B)	(QUATERNIONS((A).s*(B), VEC3_MUL1((A).v, B)))
# define QUATERNIONS_DIV1(A, B)	(QUATERNIONS((A).s/(B), VEC3_DIV1((A).v, B)))

# define QUATERNIONS_INV(A)		(QUATERNIONS())

float			ft_quaternions_length(t_quaternions const *q);
void			ft_quaternions_norm(t_quaternions *q);
t_quaternions	ft_quaternions_inv(t_quaternions const *q);

void			ft_quaternions_apply(t_quaternions const *q, t_vec3 *p);
void			ft_quaternions_reverse(t_quaternions const *q, t_vec3 *p);

t_quaternions	ft_quaternions_rot(t_vec3 rot);

#endif
