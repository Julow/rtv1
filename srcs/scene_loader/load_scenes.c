/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/02/21 23:34:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"
#include "internal.h"

#include <stddef.h>

#define PARAM(NAME,F,S,VAR)		{SUBC(NAME),V(&parse_##F),offsetof(S,VAR)}

static t_vector const	g_scene_params = VECTOR(t_param_def,
	PARAM("name", name, t_scene, name),
	PARAM("camera_pos", vec3, t_scene, camera_pos),
	PARAM("camera_dir", vec3, t_scene, camera_dir),
	PARAM("sky_color", color, t_scene, sky_color),
	PARAM("refract_index", color, t_scene, def_mtl.refract_index),
);

static t_vector const	g_light_params = VECTOR(t_param_def,
	PARAM("pos", vec3, t_light, pos),
	PARAM("brightness", vec3, t_light, brightness),
	PARAM("color", color, t_light, color),
);

static t_vector const	g_obj_params = VECTOR(t_param_def,
	PARAM("color", color, t_obj, material.color),
	PARAM("opacity", float, t_obj, opacity),
	PARAM("reflection", float, t_obj, material.reflection),
	PARAM("refract_index", float, t_obj, material.refract_index),
);

bool		parse_vec3(t_sub value, t_vec3 *dst)
{
}

bool		parse_color(t_sub value, t_vec3 *dst)
{
}

bool		parse_float(t_sub value, float *dst)
{
}

bool		parse_param(t_vector const *defs, void *data,
					t_sub param, t_sub value)
{
	uint32_t			i;
	t_param_def const	*def;

	i = 0;
	while (i < defs->length)
	{
		def = VECTOR_GET(*defs, i++);
		if (SUB_EQU(def->name, param))
			return (def->parse(value, data + def->offset));
	}
	return (false);
}

static bool	parse_scene_light(t_xml_parser *xml, t_light *light)
{
	*light = (t_light){VEC3(0.f, 0.f, 0.f), 1.f, VEC3(1.f, 1.f, 1.f)};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_END)
			break ;
		else if (xml->token != XML_TOKEN_PARAM)
			return (false);
		if (!parse_param(&g_light_params, light,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (false);
	}
	return (true);
}

static bool	parse_scene_obj(t_xml_parser *xml, t_obj **obj, t_sub obj_name)
{
	if (SUB_EQU(obj_name, SUBC("Sphere")))
		*obj = sphere_new();
	else if (SUB_EQU(obj_name, SUBC("Plane")))
		*obj = plane_new();
	else
		return (false);
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_END)
			break ;
		else if (xml->token != XML_TOKEN_PARAM)
			return (false);
		if (!parse_param(&g_obj_params, *obj,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (false);
	}
	return (true);
}

static bool	parse_scene(t_xml_parser *xml, t_scene *scene)
{
	bool		err;

	*scene = (t_scene){DSTR0(), VECTOR(t_obj*), VECTOR(t_light),
		{VEC3(0.f, 0.f, 0.f), 1.f, 0.f, 1.f}, VEC3(0.f, 0.f, 0.f)};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_PARAM)
			err = parse_param(&g_scene_params, scene,
				ft_xml_name(xml), ft_xml_value(xml));
		else if (xml->token == XML_TOKEN_START)
			err = (ft_subequ(ft_xml_name(xml), SUBC("light")))
				? parse_scene_light(xml, ft_vpush(&scene->lights, NULL, 1))
				: parse_scene_obj(xml, ft_vpush(&scene->objs, NULL, 1),
					ft_xml_name(xml));
		if (!err)
		{
			ft_dstrclear(&scene->name);
			ft_vclear(&scene->objs);
			ft_vclear(&scene->lights);
			return (false);
		}
	}
	return (true);
}

static bool	parse_scenes(t_xml_parser *xml, t_vector *dst)
{
	bool		err;

	while (ft_xml_next(xml))
	{
		if (xml->token != XML_TOKEN_START)
			err = false; // TODO: ft_xml_error
		else if (ft_subequ(ft_xml_name(xml), SUBC("scene")))
			err = parse_scene(xml, ft_vpush(dst, NULL, 1));
		else
			err = false; // TODO: ft_xml_error
		if (!err)
			return (false);
	}
	return (BOOL_OF(xml->token != XML_TOKEN_ERROR));
}

bool		load_scenes(char const *file, t_vector *dst)
{
	t_file_in		*in;
	t_xml_parser	xml_parser;
	bool			ret;

	if ((in = ft_in_open(file)) == NULL)
	{
		ft_printf("%s: Invalid file%n", file);
		return (false);
	}
	xml_parser = XML_PARSER(in);
	if (!(ret = parse_scenes(&xml_parser, dst)))
		ft_printf("%s:%u: %ts%n", file, xml_parser.line, ft_xml_value(&xml_parser));
	ft_in_close(in);
	return (ret);
}
