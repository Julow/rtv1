/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:46:30 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:25:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			rb_node_rotate(t_rb_tree *tree, t_rb_node *node, bool left)
{
	t_vec2u const		i = left ? VEC2U(1, 2) : VEC2U(2, 1);
	t_rb_node *const	pivot = RB_CHILD(node, i.y);
	t_rb_node *const	parent = RB_NODE_PARENT(node);

	if (parent == NULL)
		tree->root = pivot;
	else if (node == parent->left)
		parent->left = pivot;
	else
		parent->right = pivot;
	RB_NODE_SETPARENT(pivot, parent);
	RB_CHILD(node, i.y) = RB_CHILD(pivot, i.x);
	if (RB_CHILD(pivot, i.x) != NULL)
		RB_NODE_SETPARENT(RB_CHILD(pivot, i.x), node);
	RB_CHILD(pivot, i.x) = node;
	RB_NODE_SETPARENT(node, pivot);
}
