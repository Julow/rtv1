/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:07:00 by juloo             #+#    #+#             */
/*   Updated: 2016/06/28 14:46:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_colors.h"
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

static t_vector const	g_scene_childs = VECTOR(t_scene_child,
	{SUBC("light"), &parse_scene_light},
	{SUBC("camera"), &parse_scene_camera},
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

static bool	parse_scene_child(t_xml_parser *xml, t_parse_scene *scene)
{
	t_scene_child const	*scene_child;
	t_sub const			child_name = ft_xml_name(xml);

	scene_child = VECTOR_IT(g_scene_childs);
	while (VECTOR_NEXT(g_scene_childs, scene_child))
		if (SUB_EQU(scene_child->name, child_name))
			return (scene_child->parse(xml, scene));
	return (parse_scene_obj(xml, scene));
}

static bool	parse_scene(t_xml_parser *xml, t_scene *dst)
{
	t_parse_scene		scene;

	scene = (t_parse_scene){DSTR0(), KDTREE_BUILDER(3),
		VECTOR(t_light), VECTOR(t_camera), DEF_SKY_COLOR};
	if (!ft_xml_next(xml) || (xml->token == XML_TOKEN_PARAM
			&& !parse_xml_params(xml, &g_scene_params, &scene)))
		return (false);
	while (true)
	{
		ASSERT(xml->token == XML_TOKEN_START);
		if (!parse_scene_child(xml, &scene))
		{
			ft_dstrclear(&scene.name);
			ft_vclear(&scene.lights);
			ft_vclear(&scene.cameras);
			kdtree_builder_destroy(&scene.kdtree);
			return (false);
		}
		if (!ft_xml_next(xml))
			break ;
	}
	if (xml->token != XML_TOKEN_END)
		return (ft_xml_error(xml, SUBC("Unexpected EOF")));
	if (scene.cameras.length == 0)
		ft_vpush(&scene.cameras, &DEF_CAMERA, 1);
	*dst = (t_scene){
		DSTR_SUB(scene.name),
		kdtree_build(&scene.kdtree),
		scene.lights,
		scene.cameras,
		scene.sky_color
	};
	kdtree_builder_destroy(&scene.kdtree);
	print_kdtree(dst->objs.root, 1, '.');
	ft_logf(LOG_VERBOSE, "Scene '%ts' loaded: %u object(s), %u light(s), "
		"%u camera(s)", dst->name, dst->objs.length,
		dst->lights.length, dst->cameras.length);
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
	else if ((in = ft_in_open(ft_sub(file, 0, -1))) == NULL)
	{
		ft_dprintf(2, "%s[Error]%s %s: Invalid file%n", C_RED, C_RESET, file);
		return (false);
	}
	xml_parser = XML_PARSER(V(in));
	if (!(ret = parse_scenes(&xml_parser, dst)))
	{
		ft_dprintf(2, "%s[Error]%s %s:%u: %ts%n", C_RED, C_RESET,
			file, xml_parser.line, ft_xml_value(&xml_parser));
		// TODO: destroy scenes data on error
	}
	ft_xml_clear(&xml_parser);
	ft_in_close(in);
	return (ret);
}
