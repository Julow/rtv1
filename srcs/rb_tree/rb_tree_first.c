/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:38:05 by juloo             #+#    #+#             */
/*   Updated: 2016/04/25 17:56:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

void const		*ft_rbcfirst(t_rb_tree const *tree)
{
	t_rb_node const	*tmp;

	if ((tmp = tree->root) == NULL)
		return (NULL);
	while (tmp->left != NULL)
		tmp = tmp->left;
	return (tmp);
}

void const		*ft_rbclast(t_rb_tree const *tree)
{
	t_rb_node const	*tmp;

	if ((tmp = tree->root) == NULL)
		return (NULL);
	while (tmp->right != NULL)
		tmp = tmp->right;
	return (tmp);
}

void			*ft_rbfirst(t_rb_tree *tree)
{
	return ((void*)ft_rbcfirst(tree));
}

void			*ft_rblast(t_rb_tree *tree)
{
	return ((void*)ft_rbclast(tree));
}
