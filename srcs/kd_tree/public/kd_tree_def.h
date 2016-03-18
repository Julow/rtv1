/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kd_tree_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:15:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/18 14:41:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KD_TREE_DEF_H
# define KD_TREE_DEF_H

# include "kd_tree.h"

typedef struct s_kdtree_def			t_kdtree_def;
typedef struct s_kdtree_def_data	t_kdtree_def_data;

/*
** ========================================================================== **
** kd-tree builder
*/

struct			s_kdtree_def_data
{
	void const		*data;
	uint32_t		pt_count;
};

struct			s_kdtree_def
{
	t_vector		datas;
	t_vector		pts;
};

# define KDTREE_DEF()	((t_kdtree_def){VECTOR(t_kdtree_def_data), VECTOR(float)})

/*
** Build a kd-tree
*/
t_kdtree		kdtree_build(uint32_t k, t_kdtree_def const *def);

#endif
