/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/02/24 19:41:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_file_in.h"

#include "internal.h"
#include "scene.h"

#include <stddef.h>

static t_vector const	g_scene_params = VECTOR(t_param_def,
	PARAM("name", name, t_scene, name),
	PARAM("sky_color", color, t_scene, sky_color),
	PARAM("refract_index", color, t_scene, def_mtl.refract_index),
);

static bool	parse_scene(t_xml_parser *xml, t_scene *scene)
{
	bool		err;

	*scene = (t_scene){DSTR0(), VECTOR(t_obj), VECTOR(t_light),
		VECTOR(t_camera), DEF_MTL, DEF_SKY_COLOR};
	while (ft_xml_next(xml))
	{
		if (xml->token == XML_TOKEN_PARAM)
			err = parse_param(&g_scene_params, scene, ft_xml_name(xml),
				ft_xml_value(xml)) || ft_xml_error(xml, SUBC("Invalid value"));
		else if (xml->token == XML_TOKEN_START)
		{
			if (ft_subequ(ft_xml_name(xml), SUBC("light")))
				err = parse_scene_light(xml, ft_vpush(&scene->lights, NULL, 1));
			else if (ft_subequ(ft_xml_name(xml), SUBC("camera")))
				err = parse_scene_camera(xml, ft_vpush(&scene->cameras, NULL, 1));
			else
				err = parse_scene_obj(xml, ft_vpush(&scene->objs, NULL, 1));
		}
		else
			err = ASSERT(false);
		if (!err)
		{
			ft_dstrclear(&scene->name);
			ft_vclear(&scene->objs);
			ft_vclear(&scene->lights);
			return (false);
		}
	}
	if (scene->cameras.length == 0)
		ft_vpush(&scene->cameras, &DEF_CAMERA, 1);
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

static bool	parse_scenes(t_xml_parser *xml, t_vector *dst)
{
	while (ft_xml_next(xml))
		if (xml->token != XML_TOKEN_START)
			return (ASSERT(false));
		else if (!ft_subequ(ft_xml_name(xml), SUBC("scene")))
			return (ft_xml_error(xml, SUBC("Invalid markup")));
		else if (!parse_scene(xml, ft_vpush(dst, NULL, 1)))
			return (false);
	return (BOOL_OF(xml->token != XML_TOKEN_ERROR));
}

bool		load_scenes(char const *file, t_vector *dst)
{
	t_file_in		*in;
	t_xml_parser	xml_parser;
	bool			ret;

	if ((in = ft_in_open(file)) == NULL)
	{
		ft_dprintf(2, C_RED "[Error]" C_RESET " %s: Invalid file%n", file);
		return (false);
	}
	xml_parser = XML_PARSER(V(in));
	if (!(ret = parse_scenes(&xml_parser, dst)))
		ft_dprintf(2, C_RED "[Error]" C_RESET " %s:%u: %ts%n",
			file, xml_parser.line, ft_xml_value(&xml_parser));
	ft_in_close(in);
	return (ret);
}
