/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:34:10 by juloo             #+#    #+#             */
/*   Updated: 2016/04/28 00:20:22 by juloo            ###   ########.fr       */
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

struct			s_rb_tree
{
	t_rb_node		*root;
	int				(*cmp)(void const *node, void const *match);
	uint32_t		count;
};

# define RB_TREE(CMP)			((t_rb_tree){NULL, V(CMP), 0})

// # 		if 0

struct			s_rb_node
{
	t_rb_node		*parent;
	t_rb_node		*left;
	t_rb_node		*right;
};

# define RB_NODE_PARENT(NODE)	((t_rb_node*)(_RB_NODE(NODE) & ~1))
# define RB_NODE_ISRED(NODE)	((bool)(_RB_NODE(NODE) & 1))

# define RB_NODE_SETRED(NODE)	(_RB_NODE(NODE) |= 1)
# define RB_NODE_SETBLACK(NODE)	(_RB_NODE(NODE) &= ~1)

# define RB_NODE_SETPARENT(N,P)	(_RB_NODE(N) = (uintptr_t)(P)|RB_NODE_ISRED(N))

# define _RB_NODE(NODE)			*((uintptr_t*)&(((t_rb_node*)(NODE))->parent))

# define RB_NODE()				((t_rb_node){NULL, NULL, NULL})

// # 		else

// struct			s_rb_node
// {
// 	t_rb_node		*parent;
// 	t_rb_node		*left;
// 	t_rb_node		*right;
// 	bool			red;
// };

// # define RB_NODE_PARENT(NODE)	(((t_rb_node const*)(NODE))->parent)
// # define RB_NODE_ISRED(NODE)	(((t_rb_node const*)(NODE))->red)

// # define RB_NODE_SETRED(NODE)	((NODE)->red = true)
// # define RB_NODE_SETBLACK(NODE)	((NODE)->red = false)

// # define RB_NODE_SETPARENT(N,P)	((N)->parent = (P))

// # define RB_NODE()				((t_rb_node){NULL, NULL, NULL, false})

// # 		endif

/*
** Search through the tree
** 'match' is passed to the cmp function
** Return the matching node or NULL if not found
*/
void			*ft_rbget(t_rb_tree *tree, void const *match);
void const		*ft_rbcget(t_rb_tree const *tree, void const *match);

/*
** Insert a node into the tree
** 'match' is only used for comparaison
** 'node' should "extend" the t_rb_node struct
** Return true on success, false if dupplicate
*/
bool			ft_rbinsert(t_rb_tree *tree, void *node, void const *match);

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

#endif
