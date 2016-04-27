/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:34:10 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 01:16:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_H
# define RB_TREE_H

# include "ft/libft.h"

typedef struct s_rb_tree		t_rb_tree;
typedef struct s_rb_node		t_rb_node;

/*
** ========================================================================== **
** Red-black tree
*/

/*
** rb_tree object
** 'root' is the root node
** 'cmp' is used for comparing keys, take a node and the key to compare as args
** 'count' keep the total node count
** 'flags':
** 	RB_TREE_ALLOW_DUP		allow dupplicated keys on insert
** -
** RB_TREE(CMP, FLAGS) construct a rb_tree object
*/
struct			s_rb_tree
{
	t_rb_node		*root;
	int				(*cmp)(void const *node, void const *key);
	uint32_t		count;
	uint32_t		flags;
};

/*
** rb node header
** 'parent' is the parent node,
** 		it is also used to store the node's color
** 		RB_NODE_PARENT(NODE) return the parent node
** 		RB_NODE_ISRED(NODE) check the color flag
** 'left' and 'right' are child nodes
** -
** RB_NODE() construct a node header
** -
** node's data have to be prefixed with the t_rb_node header
*/
struct			s_rb_node
{
	t_rb_node		*parent;
	t_rb_node		*left;
	t_rb_node		*right;
};

# define RB_TREE(CMP, FLAGS)	((t_rb_tree){NULL, V(CMP), 0, (FLAGS)})

# define RB_NODE()				((t_rb_node){NULL, NULL, NULL})

# define RB_TREE_ALLOW_DUP		(1 << 1)

# define RB_NODE_PARENT(NODE)	((t_rb_node*)(_RB_NODE_P(NODE) & ~1))
# define RB_NODE_ISRED(NODE)	((bool)(_RB_NODE_P(NODE) & 1))

/*
** Search through the tree
** 'key' is passed to the cmp function
** Return the matching node or NULL if not found
*/
void			*ft_rbget(t_rb_tree *tree, void const *key);
void const		*ft_rbcget(t_rb_tree const *tree, void const *key);

/*
** Insert a node into the tree
** 'key' is only used for comparaison
** 'node' should "extend" the t_rb_node struct
** Return true on success
** Return false on dupplicated key (if RB_TREE_ALLOW_DUP flag is not set)
*/
bool			ft_rbinsert(t_rb_tree *tree, void *node, void const *key);

/*
** Remove a node
** 'node' have to be a node of 'tree'
*/
void			ft_rbremove(t_rb_tree *tree, void *node);

/*
** Return first/last node in sorted order
** Return NULL if the tree is empty
*/
void			*ft_rbfirst(t_rb_tree *tree);
void const		*ft_rbcfirst(t_rb_tree const *tree);

void			*ft_rblast(t_rb_tree *tree);
void const		*ft_rbclast(t_rb_tree const *tree);

/*
** Return the prev/next node in sorted order
** Return NULL after the last node
*/
void			*ft_rbnext(void *node);
void const		*ft_rbcnext(void const *node);

void			*ft_rbprev(void *node);
void const		*ft_rbcprev(void const *node);

/*
** -
*/

# define _RB_NODE_P(NODE)		*((uintptr_t*)&(((t_rb_node*)(NODE))->parent))

#endif
