/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:38:05 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 15:09:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "set.h"

void const		*ft_set_cfirst(t_set const *set)
{
	t_set_node const	*tmp;

	if ((tmp = set->data) == NULL)
		return (NULL);
	while (tmp->left != NULL)
		tmp = tmp->left;
	return (tmp);
}

void const		*ft_set_clast(t_set const *set)
{
	t_set_node const	*tmp;

	if ((tmp = set->data) == NULL)
		return (NULL);
	while (tmp->right != NULL)
		tmp = tmp->right;
	return (tmp);
}

void			*ft_set_first(t_set *set)
{
	return ((void*)ft_set_cfirst(set));
}

void			*ft_set_last(t_set *set)
{
	return ((void*)ft_set_clast(set));
}
