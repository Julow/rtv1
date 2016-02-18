/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 20:02:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_SPHERE_H
# define OBJ_SPHERE_H

# include "obj.h"

typedef struct s_sphere		t_sphere;

/*
** ========================================================================== **
** Sphere
*/

struct			s_sphere
{
	t_obj			obj;
	t_vec3			pos;
	float			radius;
};

t_sphere		*sphere_new(void);

#endif
