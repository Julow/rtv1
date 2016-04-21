/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:37:23 by juloo             #+#    #+#             */
/*   Updated: 2016/04/22 00:45:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

void const		*ft_rbcget(t_rb_tree const *tree, void const *match)
{
	t_rb_node const	*node;
	int				diff;

	node = tree->root;
	while (node != NULL)
	{
		diff = tree->cmp(node, match);
		if (diff == 0)
			return (node);
		node = (diff < 0) ? node->left : node->right;
	}
	return (NULL);
}

void			*ft_rbget(t_rb_tree *tree, void const *match)
{
	return ((void*)ft_rbcget(tree, match));
}
