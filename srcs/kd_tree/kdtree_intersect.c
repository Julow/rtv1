/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/18 17:51:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree.h"
#include <math.h>

typedef struct s_kdstate		t_kdstate;

struct			s_kdstate
{
	t_kdtree_child const	*node;
	float					tmin;
	float					tmax;
};

bool			kdtree_intersect(t_kdtree const *tree, float const *ray,
					t_callback intersect)
{
	t_kdstate				back[tree->height];
	t_kdstate				state;
	uint32_t				back_i;

	state = (t_kdstate){tree->root, 0.f, INFINITY};
	back_i = 0;
	while (true)
		if (state.node->type == KDTREE_LEAF)
		{
			t_vector const *const	leaf = &state.node->v.leaf;
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
			t_kdtree_node const		*n = &state.node->v.split;
			float					thit;
			t_kdtree_child const	*first;
			t_kdtree_child const	*second;

			thit = (n->p - ray[n->d]) / ray[n->d + tree->k];
			first = (ray[n->d + tree->k] > 0.f) ? n->left : n->right;
			second = (ray[n->d + tree->k] > 0.f) ? n->right : n->left;
			if (thit >= state.tmax || thit < 0)
				state.node = first;
			else if (thit <= state.tmin)
				state.node = second;
			else
			{
				back[back_i++] = (t_kdstate){second, thit, state.tmax};
				state = (t_kdstate){first, state.tmin, thit};
			}
		}
	return (false);
}
