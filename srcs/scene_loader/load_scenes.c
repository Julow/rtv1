/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/03/18 17:33:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_file_in.h"
#include "ft/ft_printf.h"

#include "internal.h"
#include "kd_tree_def.h"
#include "scene.h"

#include <stddef.h>

static t_vector const	g_scene_params = VECTOR(t_param_def,
	PARAM("name", name, t_scene, name),
	PARAM("sky_color", color, t_scene, sky_color),
	PARAM("refract_index", color, t_scene, def_mtl.refract_index),
);

static void	print_kdtree(t_kdtree_child const *node, uint32_t offset, char prefix)
{
	if (node->type == KDTREE_SPLIT)
	{
		print_kdtree(node->v.split.left, offset + 4, '/');
		ft_logf(LOG_DEBUG, "%*c- |", offset, prefix);
		print_kdtree(node->v.split.right, offset + 4, '\\');
		return ;
	}
	ft_logf(LOG_DEBUG, "%*c= %d node(s)", offset, prefix, node->v.leaf.length);
}

static bool	_parse_scene_obj(t_xml_parser *xml, t_kdtree_def *def)
{
	t_obj *const		obj = NEW(t_obj);
	t_kdtree_def_data	*data;
	t_vec3				*tmp;
	uint32_t			i;

	if (!parse_scene_obj(xml, obj))
		return (false);
	data = ft_vpush(&def->datas, NULL, 1);
	data->data = obj;
	data->pt_count = obj->type->bounds_len;
	tmp = ft_vpush(&def->pts, NULL, data->pt_count * 3);
	i = 0;
	while (i < data->pt_count)
	{
		tmp[i] = obj->type->bounds[i];
		ft_mat4apply_vec3(&obj->m, tmp + i, 1.f);
		i++;
	}
	return (true);
}

static bool	parse_scene(t_xml_parser *xml, t_scene *scene)
{
	bool			err;
	t_kdtree_def	kddef;

	*scene = (t_scene){DSTR0(), {}, VECTOR(t_light),
		VECTOR(t_camera), DEF_MTL, DEF_SKY_COLOR};
	kddef = KDTREE_DEF();
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
				err = _parse_scene_obj(xml, &kddef);
		}
		else
			err = ASSERT(false);
		if (!err)
		{
			ft_dstrclear(&scene->name);
			ft_vclear(&scene->lights);
			ft_vclear(&kddef.datas);
			ft_vclear(&kddef.pts);
			return (false);
		}
	}
	scene->objs = kdtree_build(3, &kddef);
	print_kdtree(scene->objs.root, 0, ':');
	ft_vclear(&kddef.datas);
	ft_vclear(&kddef.pts);
	if (xml->token != XML_TOKEN_END)
		return (ft_xml_error(xml, SUBC("Unexpected EOF")));
	if (scene->cameras.length == 0)
		ft_vpush(&scene->cameras, &DEF_CAMERA, 1);
	ft_logf(LOG_VERBOSE, "Scene '%ts' loaded: %u object(s), %u light(s), "
		"%u camera(s)", DSTR_SUB(scene->name), scene->objs.length,
		scene->lights.length, scene->cameras.length);
	return (true);
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
	// TODO: clear on error
	ft_in_close(in);
	return (ret);
}
