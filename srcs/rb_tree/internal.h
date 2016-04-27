/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:45:21 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:25:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "rb_tree.h"

# define RB_CHILD(NODE, I)	((t_rb_node**)(NODE))[I]

/*
** Standard tree rotation
*/
void			rb_node_rotate(t_rb_tree *tree, t_rb_node *node, bool left);

#endif
