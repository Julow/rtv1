/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:07:09 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/27 18:00:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "obj.h"
# include "ray_tracer.h"

/*
** ========================================================================== **
*/

typedef struct s_nearest		t_nearest;

struct			s_nearest
{
	t_intersect		intersect;
	t_obj const		*obj;
};

/*
** ========================================================================== **
*/

/*
** Compute the light color/intensity at a given point
** Also compute the specular effect
** TODO: compute specular somewhere else
*/
t_vec3			ray_to_light(t_ray_tracer const *scene, t_material const *mat,
					t_vertex const *ray, t_intersect const *intersect);

#endif
