/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:43:29 by juloo             #+#    #+#             */
/*   Updated: 2016/03/01 14:20:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_quaternions.h"
#include <math.h>

float			ft_quaternions_length(t_quaternions const *q)
{
	return (sqrt(q->s * q->s + VEC3_DOT(q->v, q->v)));
}

void			ft_quaternions_norm(t_quaternions *q)
{
	float const			len = ft_quaternions_length(q);

	*q = QUATERNIONS_DIV1(*q, len);
}

t_quaternions	ft_quaternions_inv(t_quaternions const *q)
{
	float const			len2 = q->s * q->s + VEC3_DOT(q->v, q->v);

	return (QUATERNIONS(q->s / len2, VEC3_SUB(VEC3_0(), VEC3_DIV1(q->v, len2))));
}

void			ft_quaternions_apply(t_quaternions const *q, t_vec3 *p)
{
	float const			len2 = q->s * q->s + VEC3_DOT(q->v, q->v);

	*p = QUATERNIONS_MUL(QUATERNIONS_MUL(*q, QUATERNIONS(0.f, *p)),
		QUATERNIONS(q->s / len2, VEC3_SUB(VEC3_0(), VEC3_DIV1(q->v, len2)))).v;
}

t_quaternions	ft_quaternions_rot(t_vec3 rot)
{
	t_quaternions			q;
	t_quaternions			tmp;

	rot = VEC3_DIV1(rot, 2.f);
	q = QUATERNIONS(1.f, VEC3_0());
	tmp = QUATERNIONS(cosf(rot.x), VEC3(sinf(rot.x), 0.f, 0.f));
	q = QUATERNIONS_MUL(q, tmp);
	tmp = QUATERNIONS(cosf(rot.y), VEC3(0.f, sinf(rot.y), 0.f));
	q = QUATERNIONS_MUL(q, tmp);
	tmp = QUATERNIONS(cosf(rot.z), VEC3(0.f, 0.f, sinf(rot.z)));
	q = QUATERNIONS_MUL(q, tmp);
	return (q);
}
