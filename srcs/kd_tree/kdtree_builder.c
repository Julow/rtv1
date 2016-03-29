/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:28:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/29 15:26:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree_builder.h"

void			kdtree_builder_push(t_kdtree_builder *b, void const *data)
{
	t_vec2u const	pt = VEC2U((b->datas.length > 0) ?
			VGET(t_vec2u, b->pts_indexes, b->datas.length - 1).y : 0,
		b->pts.length);

	ft_vpush(&b->datas, &data, 1);
	ft_vpush(&b->pts_indexes, &pt, 1);
}

void			kdtree_builder_pt(t_kdtree_builder *b,
					float const *pts, uint32_t n)
{
	float *const	dst = ft_vpush(&b->pts, NULL, n * b->k);
	t_vec2u *const	last = VECTOR_GET(b->pts_indexes, b->datas.length - 1);

	ft_memcpy(dst, pts, S(float, n * b->k));
	last->y = b->pts.length;
}

void			kdtree_builder_destroy(t_kdtree_builder *b)
{
	ft_vclear(&b->datas);
	ft_vclear(&b->pts_indexes);
	ft_vclear(&b->pts);
}
