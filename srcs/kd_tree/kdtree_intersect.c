/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/23 00:26:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree.h"
#include "math_utils.h"

#include <math.h>

bool			kdtree_intersect(t_kdtree const *tree, float const *ray,
					t_callback intersect)
{
	t_kdtree_child const	*back[tree->height];
	t_kdtree_child const	*state;
	uint32_t				back_i;

	state = tree->root;
	back_i = 0;
	while (true)
		if (state->type == KDTREE_LEAF)
		{
			t_vector const *const	leaf = &state->v.leaf;
			uint32_t				i;
			bool					ok;

			ok = false;
			i = 0;
			while (i < leaf->length)
				if (CALL(bool, intersect, VGETC(void const*, *leaf, i++), ray))
					ok = true;
			if (ok)
				return (true);
			if (back_i == 0)
				break ;
			state = back[--back_i];
		}
		else
		{
			t_kdtree_node const		*n = &state->v.split;
			float					tmp;
			// float const				pos = ray[n->d] - n->p;
			float const				pos = n->p - ray[n->d];
			float const				dir = ray[n->d + tree->k];
			t_kdtree_child const	*first;
			t_kdtree_child const	*second;

			first = (pos < 0.f) ? n->right : n->left;
			second = (pos < 0.f) ? n->left : n->right;
			if (dir != 0.f && (tmp = pos / dir) > 0)
			{
				back[back_i++] = first;
				state = second;
			}
			else
				state = first;
		}
	return (false);
}
