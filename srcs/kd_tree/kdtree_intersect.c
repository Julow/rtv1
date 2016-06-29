/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 15:37:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree.h"
#include "math_utils.h"
#include "p_kdtree.h"

#include <math.h>

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

static void		kdtree_intersect_next(t_kdtree_state *state, uint32_t *i,
					t_kdtree const *tree, float const *ray)
{
	t_kdtree_node const		*n = &state[*i].node->v.split;
	float					tmp;
	float const				dir = ray[n->d + tree->k];
	t_kdtree_child const	*first;
	t_kdtree_child const	*second;

	tmp = n->p - ray[n->d];
	first = (tmp < 0.f) ? n->right : n->left;
	second = (tmp < 0.f) ? n->left : n->right;
	tmp = (dir == 0.f) ? -1.f : tmp / dir;
	if (tmp >= state[*i].tmax || tmp < 0)
		state[*i].node = first;
	else if (tmp <= state[*i].tmin)
		state[*i].node = second;
	else
	{
		state[*i + 1] = (t_kdtree_state){first, state[*i].tmin, tmp};
		state[*i] = (t_kdtree_state){second, tmp, state[*i].tmax};
		(*i)++;
	}
}

bool			kdtree_intersect(t_kdtree const *tree, float const *ray,
					t_callback intersect)
{
	t_kdtree_state	state[tree->height + 1];
	uint32_t		i;

	i = 0;
	state[i] = (t_kdtree_state){tree->root, -INFINITY, INFINITY};
	while (true)
		if (state[i].node->type == KDTREE_LEAF)
		{
			if (intersect_leaf(&state[i].node->v.leaf, ray, intersect))
				return (true);
			if (i == 0)
				return (false);
			i--;
		}
		else
		{
			kdtree_intersect_next(state, &i, tree, ray);
		}
}
