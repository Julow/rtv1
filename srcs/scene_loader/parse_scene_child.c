/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:36:22 by juloo             #+#    #+#             */
/*   Updated: 2016/05/02 12:01:46 by jaguillo         ###   ########.fr       */
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

bool		parse_scene_light(t_xml_parser *xml, t_parse_scene *scene)
{
	t_light *const	light = ft_vpush(&scene->lights, NULL, 1);

	*light = DEF_LIGHT;
	if (!ft_xml_next(xml)
		|| (xml->token == XML_TOKEN_PARAM
			&& !parse_xml_params(xml, &g_light_params, light)))
		return (false);
	if (xml->token == XML_TOKEN_START)
		return (ft_xml_error(xml, SUBC("Can't have child")));
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

bool		parse_scene_camera(t_xml_parser *xml, t_parse_scene *scene)
{
	t_camera *const	camera = ft_vpush(&scene->cameras, NULL, 1);

	*camera = DEF_CAMERA;
	if (!ft_xml_next(xml)
		|| (xml->token == XML_TOKEN_PARAM
			&& !parse_xml_params(xml, &g_camera_params, camera)))
		return (false);
	if (xml->token == XML_TOKEN_START)
		return (ft_xml_error(xml, SUBC("Can't have child")));
	camera->dir = ft_vec3norm(camera->dir);
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

bool		parse_scene_obj(t_xml_parser *xml, t_parse_scene *scene)
{
	t_obj		*obj;

	if (!parse_obj(xml, &obj, &scene->kdtree.pts))
		return (false);
	kdtree_builder_push(&scene->kdtree, obj);
	return (true);
}
