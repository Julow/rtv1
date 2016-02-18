/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 17:43:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/math.h"

typedef struct s_vertex		t_vertex;

/*
** ========================================================================== **
*/

struct			s_vertex
{
	t_vec3			pos;
	t_vec3			dir;
};

# define VERTEX(POS,DIR)	((t_vertex){(POS), (DIR)})

#endif
