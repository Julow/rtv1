/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:42:55 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:56:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "rb_tree.h"

static void		rb_balance(t_rb_tree *tree, t_rb_node *node)
{
	t_rb_node		*parent;
	t_rb_node		*gp;

	parent = RB_NODE_PARENT(node);
	gp = RB_NODE_PARENT(parent);
	if (node == parent->right && parent == gp->left)
		rb_node_rotate(tree, node = parent, true);
	else if (node == parent->left && parent == gp->right)
		rb_node_rotate(tree, node = parent, false);
	parent = RB_NODE_PARENT(node);
	gp = RB_NODE_PARENT(parent);
	RB_NODE_SETBLACK(parent);
	RB_NODE_SETRED(gp);
	rb_node_rotate(tree, gp,
		BOOL_OF(node == parent->right && parent == gp->right));
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
		if (diff == 0 && !(tree->flags & RB_TREE_ALLOW_DUP))
			return (false);
		next = (diff <= 0) ? &parent->left : &parent->right;
	}
	ASSERT(!(((uintptr_t)node) & 1), "IMPAIR POINTER");
	tree->count++;
	*next = node;
	*(t_rb_node*)node = (t_rb_node){parent, NULL, NULL};
	if (parent != NULL)
	{
		RB_NODE_SETRED(*next);
		if (RB_NODE_ISRED(parent))
			rb_check_balance(tree, node);
	}
	return (true);
}
