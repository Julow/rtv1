/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_kdtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:11:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 13:12:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_KDTREE_H
# define P_KDTREE_H

# include "kd_tree.h"

typedef struct s_kdtree_state		t_kdtree_state;

/*
** ========================================================================== **
*/

/*
** Object used to find intersections
*/
struct			s_kdtree_state
{
	t_kdtree_child const	*node;
	float					tmin;
	float					tmax;
};

#endif
