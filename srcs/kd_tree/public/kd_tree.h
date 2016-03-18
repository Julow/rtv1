/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kd_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:14:55 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/18 17:30:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KD_TREE_H
# define KD_TREE_H

# include "ft/ft_vector.h"
# include "ft/libft.h"

typedef struct s_kdtree			t_kdtree;
typedef struct s_kdtree_node	t_kdtree_node;
typedef struct s_kdtree_child	t_kdtree_child;

/*
** ========================================================================== **
** kd-tree
*/

struct			s_kdtree
{
	uint32_t		k;
	uint32_t		height;
	uint32_t		length;
	t_kdtree_child	*root;
};

struct			s_kdtree_node
{
	uint32_t		d;
	float			p;
	t_kdtree_child	*left;
	t_kdtree_child	*right;
};

struct			s_kdtree_child
{
	enum {
		KDTREE_SPLIT,
		KDTREE_LEAF
	}				type;
	union {
		t_kdtree_node	split;
		t_vector		leaf;
	}				v;
};

/*
** Throw a ray and return the first intersection
** -
** the 'k' first floats of 'ray' are the start position,
**  the 'k' last are the ray direction
** -
** 'intersect' is of type:
**  bool (*)(void *env, void const *data, float const *ray)
*/
bool			kdtree_intersect(t_kdtree const *tree, float const *ray,
					t_callback intersect);

#endif
