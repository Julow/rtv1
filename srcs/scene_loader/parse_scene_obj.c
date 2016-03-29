/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 09:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/29 09:22:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static t_vector const	g_obj_params = VECTOR(t_param_def,
	PARAM("texture", texture, t_parse_obj, material.texture),
	PARAM("specular_map", texture, t_parse_obj, material.specular_map),
	PARAM("color", color, t_parse_obj, color),
	PARAM("specular_color", color, t_parse_obj, specular_color),
	PARAM("ambient", float, t_parse_obj, material.ambient),
	PARAM("reflection", float, t_parse_obj, material.reflection),
	PARAM("refract_index", float, t_parse_obj, material.refract_index),
	PARAM("specular_exp", float, t_parse_obj, material.specular_exp),
	PARAM("pos", vec3, t_parse_obj, pos),
	PARAM("rot", vec3, t_parse_obj, rot),
	PARAM("shear", vec3, t_parse_obj, shear),
	PARAM("scale", vec3, t_parse_obj, scale),
);

bool		parse_scene_obj(t_xml_parser *xml, t_obj *obj,
				t_parse_obj_t const *obj_t)
{
	t_parse_obj					p;

	p = (t_parse_obj){DEF_MTL, 0, 0xFFFFFF, VEC3_0(), VEC3_0(),
		VEC3_0(), VEC3_1(1.f), obj};
	while (ft_xml_next(xml))
		if (xml->token == XML_TOKEN_START)
		{
			if (!obj_t->parse_child(xml, &p))
				return (false);
		}
		else if (xml->token == XML_TOKEN_PARAM)
		{
			if (!parse_param(xml, &g_obj_params, obj)
				&& (xml->token == XML_TOKEN_ERROR
					|| !obj_t->parse_param(xml, &p)))
					return (false);
		}
		else
			ASSERT(xml->token == XML_TOKEN_PARAM);
	if (xml->token != XML_TOKEN_END)
		return (false);
	(*obj)->material = p.material;
	p.rot = VEC3_MUL1(p.rot, M_PI/2.f);
	(*obj)->m = ft_mat4transform(p.pos, p.rot, p.shear, p.scale);
	(*obj)->m_inv = ft_mat4transform_inv(p.pos, p.rot, p.shear, p.scale);
	if ((*obj)->material.texture == NULL)
		(*obj)->material.texture = load_texture1(p.color);
	if ((*obj)->material.specular_map == NULL)
		(*obj)->material.specular_map = load_texture1(p.specular_color);
	return (true);
}
