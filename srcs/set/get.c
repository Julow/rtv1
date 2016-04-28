/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:37:23 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 15:09:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "set.h"

void const		*ft_set_cget(t_set const *set, void const *key)
{
	t_set_node const	*node;
	int					diff;

	node = set->data;
	while (node != NULL)
	{
		diff = set->cmp(node, key);
		if (diff == 0)
			return (node);
		node = (diff < 0) ? node->left : node->right;
	}
	return (NULL);
}

void			*ft_set_get(t_set *set, void const *key)
{
	return ((void*)ft_set_cget(set, key));
}
