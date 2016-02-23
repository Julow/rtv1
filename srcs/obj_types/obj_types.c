/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:01:47 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 18:17:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "obj_types.h"

static t_obj_class const	g_obj_types[] = {
	{SUBC("sphere"), &sphere_ray_intersect},
	{SUBC("plane"), &plane_ray_intersect},
	{SUBC("cylinder"), &cylinder_ray_intersect},
};

t_obj_class const	*get_obj_class(t_sub name)
{
	uint32_t			i;

	i = 0;
	while (i < ARRAY_LEN(g_obj_types))
	{
		if (SUB_EQU(name, g_obj_types[i].name))
			return (g_obj_types + i);
		i++;
	}
	return (NULL);
}
