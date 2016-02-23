/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/23 18:14:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_SPHERE_H
# define OBJ_SPHERE_H

# include "obj.h"

/*
** Return the obj class named 'name'
** Return NULL if not found
*/
t_obj_class const	*get_obj_class(t_sub name);

#endif
