/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:01:47 by juloo             #+#    #+#             */
/*   Updated: 2016/03/29 08:50:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "obj_types.h"

static t_vec3 const			g_bounds_cube[] = {
	{-1.f, 1.f, -1.f},
	{-1.f, 1.f, 1.f},
	{1.f, 1.f, 1.f},
	{1.f, 1.f, -1.f},
	{-1.f, -1.f, -1.f},
	{-1.f, -1.f, 1.f},
	{1.f, -1.f, 1.f},
	{1.f, -1.f, -1.f},
};

static t_obj_class_t const	g_obj_types[] = {
	{{SUBC("sphere"), &sphere_ray_intersect, &obj_xml_event_none,
		g_bounds_cube, 8}, 0},
	{{SUBC("plane"), &plane_ray_intersect, &obj_xml_event_none,
		(t_vec3[]){
			{-0.5f, 0.f, -0.5f},
			{-0.5f, 0.f, 0.5f},
			{0.5f, 0.f, 0.5f},
			{0.5f, 0.f, -0.5f},
		}, 4}, 0},
	{{SUBC("cylinder"), &cylinder_ray_intersect, &obj_xml_event_none,
		g_bounds_cube, 8}, 0},
	{{SUBC("cone"), &cone_ray_intersect, &obj_xml_event_none,
		(t_vec3[]){
			{0.f, 0.f, 0.f},
			{-1.f, 1.f, -1.f},
			{1.f, 1.f, -1.f},
			{1.f, -1.f, -1.f},
			{-1.f, -1.f, -1.f},
		}, 5}, 0},
};

bool				obj_xml_event_none(t_obj *obj, t_xml_parser *xml)
{
	if (xml->token == XML_TOKEN_START)
		return (ft_xml_error(xml, SUBC("Can't have child")));
	if (xml->token == XML_TOKEN_PARAM)
		return (ft_xml_error(xml, SUBC("Invalid param")));
	return (ASSERT(false));
	(void)obj;
}

t_obj				*create_obj(t_sub type_name)
{
	uint32_t			i;
	t_obj				*obj;

	i = 0;
	while (i < ARRAY_LEN(g_obj_types))
	{
		if (SUB_EQU(type_name, g_obj_types[i].name))
		{
			obj = MALLOC(sizeof(t_obj) + g_obj_types[i].extra_size);
			ft_bzero(obj, sizeof(t_obj) + g_obj_types[i].extra_size);
			obj->type = &g_obj_types[i].type;
			return (obj);
		}
		i++;
	}
	return (NULL);
}
