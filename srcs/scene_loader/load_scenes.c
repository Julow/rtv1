/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 18:18:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"
#include "ft/ft_xml.h"

#include "internal.h"
#include "obj_types.h"
#include "scene.h"

#include <stddef.h>

static t_vector const	g_scene_params = VECTOR(t_param_def,
	PARAM("name", name, t_scene, name),
	PARAM("sky_color", color, t_scene, sky_color),
	PARAM("refract_index", color, t_scene, def_mtl.refract_index),
);

static t_vector const	g_light_params = VECTOR(t_param_def,
	PARAM("pos", vec3, t_light, pos),
	PARAM("brightness", float, t_light, brightness),
	PARAM("color", color, t_light, color),
);

static t_vector const	g_obj_params = VECTOR(t_param_def,
	PARAM("color", color, t_parse_obj, material.color),
	PARAM("opacity", float, t_parse_obj, material.opacity),
	PARAM("reflection", float, t_parse_obj, material.reflection),
	PARAM("refract_index", float, t_parse_obj, material.refract_index),
	PARAM("pos", vec3, t_parse_obj, transform.pos),
	PARAM("rot", vec3, t_parse_obj, transform.rot),
	PARAM("shear", vec3, t_parse_obj, transform.shear),
	PARAM("scale", vec3, t_parse_obj, transform.scale),
);

static bool	parse_scene_light(t_xml_parser *xml, t_light *light)
{
	*light = (t_light){VEC3(0.f, 0.f, 0.f), 1.f, VEC3(0.f, 0.f, 0.f)};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_END)
			break ;
		else if (xml->token != XML_TOKEN_PARAM)
			return (false); // TODO: ft_xml_error
		if (!parse_param(&g_light_params, light,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (false); // TODO: ft_xml_error
	}
	return (true);
}

static bool	parse_scene_obj(t_xml_parser *xml, t_obj *obj)
{
	t_parse_obj					p;
	t_obj_class const *const	c = get_obj_class(ft_xml_name(xml));

	if (c == NULL)
		return (false); // TODO: ft_xml_error
	p.material = C(t_material, VEC3_0(), 1.f, 0.f, 1.f);
	p.transform = TRANSFORM(VEC3_0(), VEC3_0(), VEC3_0(), VEC3_1(1.f));
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_END)
			break ;
		else if (xml->token != XML_TOKEN_PARAM)
			return (false); // TODO: ft_xml_error
		if (!parse_param(&g_obj_params, &p,
				ft_xml_name(xml), ft_xml_value(xml)))
			return (false); // TODO: ft_xml_error
	}
	obj->type = c;
	obj->material = p.material;
	transform_matrix(&p.transform, &obj->m, &obj->m_inv);
	return (true);
}

static bool	parse_scene(t_xml_parser *xml, t_scene *scene)
{
	bool		err;

	*scene = (t_scene){DSTR0(), VECTOR(t_obj), VECTOR(t_light),
		{VEC3(0.f, 0.f, 0.f), 1.f, 0.f, 1.f}, VEC3(0.f, 0.f, 0.f)};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_PARAM)
			err = parse_param(&g_scene_params, scene,
				ft_xml_name(xml), ft_xml_value(xml)); // TODO: || ft_xml_error
		else if (xml->token == XML_TOKEN_START)
			err = (ft_subequ(ft_xml_name(xml), SUBC("light")))
				? parse_scene_light(xml, ft_vpush(&scene->lights, NULL, 1))
				: parse_scene_obj(xml, ft_vpush(&scene->objs, NULL, 1));
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
	xml_parser = XML_PARSER(V(in));
	if (!(ret = parse_scenes(&xml_parser, dst)))
		ft_printf("%s:%u: %ts%n", file, xml_parser.line, ft_xml_value(&xml_parser));
	ft_in_close(in);
	return (ret);
}
