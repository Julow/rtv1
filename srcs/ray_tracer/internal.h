/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:07:09 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 16:33:43 by jaguillo         ###   ########.fr       */
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

#endif
