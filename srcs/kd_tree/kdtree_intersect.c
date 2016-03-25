/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/25 15:34:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree.h"
#include "math_utils.h"

#include <math.h>

typedef struct s_kdtree_state		t_kdtree_state;

struct			s_kdtree_state
{
	t_kdtree_child const	*node;
	float					tmin;
	float					tmax;
};

static bool		intersect_leaf(t_vector const *leaf, float const *ray,
					t_callback intersect)
{
	uint32_t		i;
	bool			ok;

	i = 0;
	ok = false;
	while (i < leaf->length)
		if (CALL(bool, intersect, VGETC(void const*, *leaf, i++), ray))
			ok = true;
	return (ok);
}

bool			kdtree_intersect(t_kdtree const *tree, float const *ray,
					t_callback intersect)
{
	t_kdtree_state	back[tree->height];
	t_kdtree_state	state;
	uint32_t		back_i;

	state = (t_kdtree_state){tree->root, -INFINITY, INFINITY};
	back_i = 0;
	while (true)
		if (state.node->type == KDTREE_LEAF)
		{
			if (intersect_leaf(&state.node->v.leaf, ray, intersect))
				return (true);
			if (back_i == 0)
				return (false);
			state = back[--back_i];
		}
		else
		{
			t_kdtree_node const		*n = &state.node->v.split;
			float					tmp;
			float const				dir = ray[n->d + tree->k];
			t_kdtree_child const	*first;
			t_kdtree_child const	*second;

			tmp = n->p - ray[n->d];
			first = (tmp < 0.f) ? n->right : n->left;
			second = (tmp < 0.f) ? n->left : n->right;
			tmp = (dir == 0.f) ? -1.f : tmp / dir;
			if (tmp >= state.tmax || tmp < 0)
				state.node = first;
			else if (tmp <= state.tmin)
				state.node = second;
			else
			{
				back[back_i++] = (t_kdtree_state){second, tmp, state.tmax};
				state.node = first;
				state.tmax = tmp;
			}
		}
}
