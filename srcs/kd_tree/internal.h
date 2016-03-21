/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:32:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/21 08:56:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

#include "kd_tree.h"
#include "kd_tree_def.h"

typedef struct s_kdtree_build		t_kdtree_build;

/*
** ========================================================================== **
*/

struct			s_kdtree_build
{
	t_kdtree			tree;
	t_kdtree_def const	*def;
	uint32_t			height;
};

// TODO: improve
#define MAX_HEIGHT		10

#endif
