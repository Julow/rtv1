/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:35:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 19:56:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/libft.h"
# include "ft/math.h"

# include "math_utils.h"

typedef struct s_obj			t_obj;
typedef struct s_obj_class		t_obj_class;

/*
** ========================================================================== **
** Obj
*/

/*
** Represent an object type
** 'ray_intersect' have to find the intersection between 'ray' and 'obj'
**   or to return false if there is no intersection
*/
struct			s_obj_class
{
	t_sub			name;
	bool			(*ray_intersect)(t_vertex *intersect, t_obj const *obj,
						t_vertex const *ray);
};

/*
** Object
*/
struct			s_obj
{
	t_obj_class const	*type;
	t_vec4				color;
	float				refract_index;
};

#endif
