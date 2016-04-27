/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:31:30 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:31:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "rb_tree.h"

static void		rb_balance(t_rb_tree *tree, t_rb_node *node)
{
	t_rb_node		*sibling;
	t_rb_node		*parent;
	t_vec2u			i;

	while ((parent = RB_NODE_PARENT(node)) != NULL && !RB_NODE_ISRED(node))
	{
		i = ((node == parent->left) || (parent->left == NULL
				&& node != parent->right)) ? VEC2U(1, 2) : VEC2U(2, 1);
		sibling = RB_CHILD(parent, i.y);
		if (RB_NODE_ISRED(sibling))
		{
			RB_NODE_SETBLACK(sibling);
			RB_NODE_SETRED(parent);
			rb_node_rotate(tree, parent, i.x == 1);
			sibling = RB_CHILD(parent, i.y);
		}
		if ((sibling->left == NULL || !RB_NODE_ISRED(sibling->left))
			&& (sibling->right == NULL || !RB_NODE_ISRED(sibling->right)))
		{
			RB_NODE_SETRED(sibling);
			node = parent;
			continue ;
		}
		if (RB_CHILD(sibling, i.y) == NULL
			|| !RB_NODE_ISRED(RB_CHILD(sibling, i.y)))
		{
			RB_NODE_SETBLACK(RB_CHILD(sibling, i.x));
			RB_NODE_SETRED(sibling);
			rb_node_rotate(tree, sibling, i.y == 1);
			sibling = RB_CHILD(parent, i.y);
		}
		if (RB_NODE_ISRED(parent))
			RB_NODE_SETRED(sibling);
		else
			RB_NODE_SETBLACK(sibling);
		RB_NODE_SETBLACK(parent);
		RB_NODE_SETBLACK(RB_CHILD(sibling, i.y));
		rb_node_rotate(tree, parent, i.x == 1);
		break ;
	}
	RB_NODE_SETBLACK(node);
}

static void		rb_swap_node(t_rb_tree *tree, t_rb_node *a, t_rb_node *b)
{
	t_rb_node			*parent;

	if (a->left == a)
		a->left = b;
	else if (a->right == a)
		a->right = b;
	if (a->left != NULL)
		RB_NODE_SETPARENT(a->left, a);
	if (a->right != NULL)
		RB_NODE_SETPARENT(a->right, a);
	if ((parent = RB_NODE_PARENT(a)) == NULL)
		tree->root = a;
	else if (parent->left == b)
		parent->left = a;
	else if (parent->right == b)
		parent->right = a;
}

static void		rb_node_swap(t_rb_tree *tree, t_rb_node *a, t_rb_node *b)
{
	t_rb_node			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	rb_swap_node(tree, a, b);
	rb_swap_node(tree, b, a);
}

void			ft_rbremove(t_rb_tree *tree, void *node)
{
	t_rb_node			*tmp;
	t_rb_node *const	n = (t_rb_node*)node;
	t_rb_node			*parent;

	tree->count--;
	if (n->left != NULL && n->right != NULL)
		rb_node_swap(tree, ft_rbnext(n), n);
	tmp = (n->left != NULL) ? n->left : n->right;
	if ((parent = RB_NODE_PARENT(n)) == NULL)
		tree->root = tmp;
	else if (n == parent->left)
		parent->left = tmp;
	else
		parent->right = tmp;
	if (tmp == NULL)
		tmp = n;
	RB_NODE_SETPARENT(tmp, parent);
	if (!RB_NODE_ISRED(n))
		rb_balance(tree, tmp);
	*n = RB_NODE();
}
