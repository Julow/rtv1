/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:25:21 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 15:07:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "set.h"

void const		*ft_set_cnext(void const *element)
{
	t_set_node const	*tmp;

	if ((tmp = ((t_set_node const*)element)->right) != NULL)
	{
		while (tmp->left != NULL)
			tmp = tmp->left;
	}
	else
	{
		tmp = SET_PARENT(element);
		while (tmp != NULL && element == tmp->right)
			tmp = SET_PARENT(element = tmp);
	}
	return (tmp);
}

void const		*ft_set_cprev(void const *element)
{
	t_set_node const	*tmp;

	if ((tmp = ((t_set_node const*)element)->left) != NULL)
	{
		while (tmp->right != NULL)
			tmp = tmp->right;
	}
	else
	{
		tmp = SET_PARENT(element);
		while (tmp != NULL && element == tmp->left)
			tmp = SET_PARENT(element = tmp);
	}
	return (tmp);
}

void			*ft_set_next(void *element)
{
	return ((void*)(ft_set_cnext(element)));
}

void			*ft_set_prev(void *element)
{
	return ((void*)(ft_set_cprev(element)));
}
