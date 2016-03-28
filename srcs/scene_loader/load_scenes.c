/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/03/28 10:27:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_file_in.h"
#include "ft/ft_printf.h"

#include "internal.h"
#include "kd_tree_builder.h"
#include "scene.h"

#include <stddef.h>
#include <stdlib.h>

static t_vector const	g_scene_params = VECTOR(t_param_def,
	PARAM("name", name, t_scene, name),
	PARAM("sky_color", color, t_scene, sky_color),
);

static void	print_kdtree(t_kdtree_child const *node, uint32_t offset, char prefix)
{
	if (node->type == KDTREE_SPLIT)
	{
		print_kdtree(node->v.split.left, offset + 4, '/');
		ft_logf(LOG_DEBUG, "%*c %c|", offset, prefix, "xyz"[node->v.split.d]);
		print_kdtree(node->v.split.right, offset + 4, '\\');
		return ;
	}
	ft_logf(LOG_DEBUG, "%*c= %d node(s)", offset, prefix, node->v.leaf.length);
}

static bool	_parse_scene_obj(t_xml_parser *xml, t_kdtree_builder *b)
{
	t_obj *const		obj = NEW(t_obj);
	t_vec3				tmp;
	uint32_t			i;

	if (!parse_scene_obj(xml, obj))
		return (free(obj), false);
	kdtree_builder_push(b, obj);
	i = 0;
	while (i < obj->type->bounds_len)
	{
		tmp = obj->type->bounds[i];
		ft_mat4apply_vec3(&obj->m, &tmp, 1.f);
		kdtree_builder_pt(b, (float*)&tmp, 1);
		i++;
	}
	return (true);
}

static bool	parse_scene(t_xml_parser *xml, t_scene *scene)
{
	bool				err;
	t_kdtree_builder	kdbuilder;

	*scene = (t_scene){DSTR0(), {}, VECTOR(t_light),
		VECTOR(t_camera), DEF_SKY_COLOR};
	kdbuilder = KDTREE_BUILDER(3);
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
				err = _parse_scene_obj(xml, &kdbuilder);
		}
		else
			err = ASSERT(false);
		if (!err)
		{
			ft_dstrclear(&scene->name);
			ft_vclear(&scene->lights);
			kdtree_builder_destroy(&kdbuilder);
			return (false);
		}
	}
	scene->objs = kdtree_build(&kdbuilder);
	kdtree_builder_destroy(&kdbuilder);
	print_kdtree(scene->objs.root, 1, '.');
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

	if (file[0] == '-' && file[1] == '\0')
		in = ft_in_fdopen(0);
	else if ((in = ft_in_open(file)) == NULL)
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
