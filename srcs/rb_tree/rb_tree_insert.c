/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:42:55 by juloo             #+#    #+#             */
/*   Updated: 2016/04/22 00:43:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

#define RB_CHILD(NODE, I)	((t_rb_node**)(NODE))[I]

static void		rb_rotate(t_rb_tree *tree, t_rb_node *node, bool left)
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

static void		rb_balance(t_rb_tree *tree, t_rb_node *node)
{
	t_rb_node		*parent;
	t_rb_node		*gp;

	parent = RB_NODE_PARENT(node);
	gp = RB_NODE_PARENT(parent);
	if (node == parent->right && parent == gp->left)
		rb_rotate(tree, node = parent, true);
	else if (node == parent->left && parent == gp->right)
		rb_rotate(tree, node = parent, false);
	parent = RB_NODE_PARENT(node);
	gp = RB_NODE_PARENT(parent);
	RB_NODE_SETBLACK(parent);
	RB_NODE_SETRED(gp);
	rb_rotate(tree, gp, BOOL_OF(node == parent->right && parent == gp->right));
}

static void		rb_check_balance(t_rb_tree *tree, t_rb_node *node)
{
	t_rb_node		*parent;
	t_rb_node		*gp;
	t_rb_node		*uncle;

	parent = RB_NODE_PARENT(node);
	while (true)
	{
		gp = RB_NODE_PARENT(parent);
		ASSERT(gp != NULL);
		uncle = (gp->left == parent) ? gp->right : gp->left;
		if (uncle == NULL || !RB_NODE_ISRED(uncle))
			return (rb_balance(tree, node));
		RB_NODE_SETBLACK(parent);
		RB_NODE_SETBLACK(uncle);
		node = gp;
		parent = RB_NODE_PARENT(node);
		if (parent == NULL)
			break ;
		RB_NODE_SETRED(node);
		if (!RB_NODE_ISRED(parent))
			break ;
	}
}

bool			ft_rbinsert(t_rb_tree *tree, void *node, void const *match)
{
	t_rb_node		*parent;
	t_rb_node		**next;
	int				diff;

	parent = NULL;
	next = &tree->root;
	while (*next != NULL)
	{
		parent = *next;
		diff = tree->cmp(parent, match);
		if (diff == 0)
			return (false);
		next = (diff < 0) ? &parent->left : &parent->right;
	}
	ASSERT(!(((uintptr_t)node) & 1), "IMPAIR POINTER");
	tree->count++;
	*next = node;
	*(t_rb_node*)node = (t_rb_node){parent, NULL, NULL};
	if (parent != NULL)
	{
		RB_NODE_SETRED((t_rb_node*)node);
		if (RB_NODE_ISRED(parent))
			rb_check_balance(tree, node);
	}
	return (true);
}
