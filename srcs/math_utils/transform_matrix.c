/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:44:44 by juloo             #+#    #+#             */
/*   Updated: 2016/02/22 22:45:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

void			transform_matrix(t_transform const *t, t_mat4 *m, t_mat4 *m_inv)
{
	if (m != NULL)
	{
		*m = MAT4_I();
		ft_mat4translate(m, t->pos);
		ft_mat4scale3(m, t->scale);
		ft_mat4shear(m, t->shear);
		ft_mat4rotate(m, t->rot);
	}
	if (m_inv != NULL)
	{
		*m_inv = MAT4_I();
		ft_mat4rotate_inv(m_inv, t->rot);
		ft_mat4shear(m_inv, VEC3_SUB(VEC3_0(), t->shear));
		ft_mat4scale3(m_inv, VEC3_DIV(VEC3_1(1.f), t->scale));
		ft_mat4translate(m_inv, VEC3_SUB(VEC3_0(), t->pos));
	}
}
