/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:25:21 by juloo             #+#    #+#             */
/*   Updated: 2016/04/25 17:51:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

void const		*ft_rbcnext(void const *node)
{
	t_rb_node const	*tmp;

	if ((tmp = ((t_rb_node const*)node)->right) != NULL)
	{
		while (tmp->left != NULL)
			tmp = tmp->left;
	}
	else
	{
		tmp = RB_NODE_PARENT(node);
		while (tmp != NULL && node == tmp->right)
			tmp = RB_NODE_PARENT(node = tmp);
	}
	return (tmp);
}

void const		*ft_rbcprev(void const *node)
{
	t_rb_node const	*tmp;

	if ((tmp = ((t_rb_node const*)node)->left) != NULL)
	{
		while (tmp->right != NULL)
			tmp = tmp->right;
	}
	else
	{
		tmp = RB_NODE_PARENT(node);
		while (tmp != NULL && node == tmp->left)
			tmp = RB_NODE_PARENT(node = tmp);
	}
	return (tmp);
}

void			*ft_rbnext(void *node)
{
	return ((void*)(ft_rbcnext(node)));
}

void			*ft_rbprev(void *node)
{
	return ((void*)(ft_rbcprev(node)));
}
