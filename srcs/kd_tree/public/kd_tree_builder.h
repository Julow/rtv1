/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kd_tree_builder.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:24:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 13:09:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KD_TREE_BUILDER_H
# define KD_TREE_BUILDER_H

# include "kd_tree.h"

typedef struct s_kdtree_builder		t_kdtree_builder;

/*
** ========================================================================== **
** kd-tree builder
*/

struct			s_kdtree_builder
{
	uint32_t		k;
	uint32_t		height;
	uint32_t		max_height;
	t_vector		datas;
	t_vector		pts_indexes;
	t_vector		pts;
};

# define KDTREE_BUILDER(K)	((t_kdtree_builder){(K), 0, 0, _KDTREE_BUILDER})

/*
** Create a new data entry
*/
void			kdtree_builder_push(t_kdtree_builder *b, void const *data);

/*
** Add a point to the last entry
** -
** 'pts' must point to n * k floats
*/
void			kdtree_builder_pt(t_kdtree_builder *b,
					float const *pts, uint32_t n);

/*
** Build a kdtree
** -
** Automatically call kdtree_builder_destroy
*/
t_kdtree		kdtree_build(t_kdtree_builder *b);

/*
** Clear the kdtree builder
*/
void			kdtree_builder_destroy(t_kdtree_builder *b);

/*
** -
*/

# define _KDTREE_BUILDER	VECTOR(void const*), VECTOR(t_vec2u), VECTOR(float)

#endif
