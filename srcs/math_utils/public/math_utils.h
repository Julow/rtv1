/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 22:02:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "ft/math.h"

typedef struct s_vertex		t_vertex;

/*
** ========================================================================== **
** Vertex
*/

struct			s_vertex
{
	t_vec3			pos;
	t_vec3			dir;
};

# define VERTEX(POS,DIR)	((t_vertex){(POS), (DIR)})

/*
** ========================================================================== **
*/

# define VEC3_DOT(A, B)	(((A).x * (B).x) + ((A).y * (B).y) + ((A).z * (B).z))

float			ft_vec3length(t_vec3 v);

float			ft_vec3dist(t_vec3 a, t_vec3 b);
float			ft_vec3dist2(t_vec3 a, t_vec3 b);

t_vec3			ft_vec3mix(t_vec3 a, t_vec3 b, float mix);

#endif
