/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:36:22 by juloo             #+#    #+#             */
/*   Updated: 2016/03/14 17:23:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "internal.h"
#include "obj_types.h"
#include "scene.h"
#include "texture_loader.h"

#include <math.h>
#include <stddef.h>

static t_vector const	g_light_params = VECTOR(t_param_def,
	PARAM("pos", vec3, t_light, pos),
	PARAM("brightness", float, t_light, brightness),
	PARAM("color", colorf, t_light, color),
	PARAM("attenuation", float, t_light, att_dist),
	PARAM("attenuation_exp", float, t_light, att_exp),
);

static t_vector const	g_camera_params = VECTOR(t_param_def,
	PARAM("pos", vec3, t_camera, pos),
	PARAM("dir", vec3, t_camera, dir),
);

static t_vector const	g_obj_params = VECTOR(t_param_def,
	PARAM("texture", texture, t_parse_obj, material.texture),
	PARAM("specular_map", texture, t_parse_obj, material.specular_map),
	PARAM("color", color, t_parse_obj, color),
	PARAM("specular_color", color, t_parse_obj, specular_color),
	PARAM("ambient", float, t_parse_obj, material.ambient),
	PARAM("opacity", float, t_parse_obj, material.opacity),
	PARAM("reflection", float, t_parse_obj, material.reflection),
	PARAM("refract_index", float, t_parse_obj, material.refract_index),
	PARAM("specular_exp", float, t_parse_obj, material.specular_exp),
	PARAM("pos", vec3, t_parse_obj, pos),
	PARAM("rot", vec3, t_parse_obj, rot),
	PARAM("shear", vec3, t_parse_obj, shear),
	PARAM("scale", vec3, t_parse_obj, scale),
);

bool		parse_scene_light(t_xml_parser *xml, t_light *light)
{
	*light = DEF_LIGHT;
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_START)
			return (ft_xml_error(xml, SUBC("Can't have child")));
		ASSERT(xml->token == XML_TOKEN_PARAM);
		if (!parse_param(&g_light_params, light,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (ft_xml_error(xml, SUBC("Invalid value")));
	}
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

bool		parse_scene_camera(t_xml_parser *xml, t_camera *camera)
{
	*camera = DEF_CAMERA;
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_START)
			return (ft_xml_error(xml, SUBC("Can't have child")));
		ASSERT(xml->token == XML_TOKEN_PARAM);
		if (!parse_param(&g_camera_params, camera,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (ft_xml_error(xml, SUBC("Invalid value")));
	}
	camera->dir = ft_vec3norm(camera->dir);
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

bool		parse_scene_obj(t_xml_parser *xml, t_obj *obj)
{
	t_parse_obj					p;
	t_obj_class const *const	c = get_obj_class(ft_xml_name(xml));

	if (c == NULL)
		return (ft_xml_error(xml, SUBC("Unknown obj type")));
	p = (t_parse_obj){DEF_MTL, 0, 0xFFFFFF, VEC3_0(), VEC3_0(), VEC3_0(), VEC3_1(1.f)};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_START)
			return (ft_xml_error(xml, SUBC("Can't have child")));
		ASSERT(xml->token == XML_TOKEN_PARAM);
		if (!parse_param(&g_obj_params, &p,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (ft_xml_error(xml, SUBC("Invalid value")));
	}
	if (xml->token != XML_TOKEN_END)
		return (false);
	obj->type = c;
	obj->material = p.material;
	p.rot = VEC3_MUL1(p.rot, M_PI/2.f);
	obj->m = ft_mat4transform(p.pos, p.rot, p.shear, p.scale);
	obj->m_inv = ft_mat4transform_inv(p.pos, p.rot, p.shear, p.scale);
	if (obj->material.texture == NULL)
		obj->material.texture = load_texture1(p.color);
	if (obj->material.specular_map == NULL)
		obj->material.specular_map = load_texture1(p.specular_color);
	return (true);
}
