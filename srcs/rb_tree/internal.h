/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:45:21 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:47:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "rb_tree.h"

# define RB_CHILD(NODE, I)		((t_rb_node**)(NODE))[I]

# define RB_NODE_SETRED(NODE)	(_RB_NODE_P(NODE) |= 1)
# define RB_NODE_SETBLACK(NODE)	(_RB_NODE_P(NODE) &= ~1)

# define RB_NODE_SETPARENT(N,P)	(_RB_NODE_P(N)=(uintptr_t)(P)|RB_NODE_ISRED(N))

/*
** Standard tree rotation
*/
void			rb_node_rotate(t_rb_tree *tree, t_rb_node *node, bool left);

#endif
