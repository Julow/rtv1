/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:52:08 by juloo             #+#    #+#             */
/*   Updated: 2016/02/28 01:37:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

void			ft_mat4apply_vec4(t_mat4 const *m, t_vec4 *v)
{
	t_vec4 const	tmp = *v;

	v->x = VEC4_DOT(m->x, tmp);
	v->y = VEC4_DOT(m->y, tmp);
	v->z = VEC4_DOT(m->z, tmp);
	v->w = VEC4_DOT(m->w, tmp);
}

void			ft_mat4apply_vec3(t_mat4 const *m, t_vec3 *v)
{
	t_vec3 const	tmp = *v;

	v->x = VEC3_DOT(m->x, tmp) + m->x.w;
	v->y = VEC3_DOT(m->y, tmp) + m->y.w;
	v->z = VEC3_DOT(m->z, tmp) + m->z.w;
}

void			ft_mat4apply_vertex(t_mat4 const *m, t_vertex *v)
{
	t_vec3			b;

	b = VEC3_ADD(v->pos, v->dir);
	ft_mat4apply_vec3(m, &v->pos);
	ft_mat4apply_vec3(m, &b);
	v->dir = ft_vec3norm(VEC3_SUB(b, v->pos));
}