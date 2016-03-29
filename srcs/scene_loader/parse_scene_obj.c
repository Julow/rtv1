/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 09:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/29 15:23:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "obj_types.h"
#include "texture_loader.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

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

static t_vec3 const		g_bounds_cube[] = {
	{-1.f, 1.f, -1.f},
	{-1.f, 1.f, 1.f},
	{1.f, 1.f, 1.f},
	{1.f, 1.f, -1.f},
	{-1.f, -1.f, -1.f},
	{-1.f, -1.f, 1.f},
	{1.f, -1.f, 1.f},
	{1.f, -1.f, -1.f},
};

static t_vector const	g_parse_objs = VECTOR(t_parse_obj_t,
	{SUBC("sphere"),
		&sphere_ray_intersect,
		&parse_scene_obj_child, &parse_scene_obj_param,
		0,
		g_bounds_cube, 8
	},
	{SUBC("plane"),
		&plane_ray_intersect,
		&parse_scene_obj_child, &parse_scene_obj_param,
		0,
		(t_vec3[]){
			{-0.5f, 0.f, -0.5f},
			{-0.5f, 0.f, 0.5f},
			{0.5f, 0.f, 0.5f},
			{0.5f, 0.f, -0.5f},
		}, 4
	},
	{SUBC("cylinder"),
		&cylinder_ray_intersect,
		&parse_scene_obj_child, &parse_scene_obj_param,
		0,
		g_bounds_cube, 8
	},
	{SUBC("cone"),
		&cone_ray_intersect,
		&parse_scene_obj_child, &parse_scene_obj_param,
		0,
		(t_vec3[]){
			{0.f, 0.f, 0.f},
			{-1.f, 1.f, -1.f},
			{1.f, 1.f, -1.f},
			{1.f, -1.f, -1.f},
			{-1.f, -1.f, -1.f},
		}, 5
	},
);

bool		parse_scene_obj_param(t_xml_parser *xml, t_obj *obj)
{
	return (ft_xml_error(xml, SUBC("Unknown param")));
	(void)obj;
}

bool		parse_scene_obj_child(t_xml_parser *xml, t_obj *obj)
{
	return (ft_xml_error(xml, SUBC("Can't have child")));
	(void)obj;
}

static t_parse_obj_t const	*get_obj_t(t_sub obj_type)
{
	t_parse_obj_t const	*t;

	t = VECTOR_IT(g_parse_objs);
	while (VECTOR_NEXT(g_parse_objs, t))
		if (SUB_EQU(t->name, obj_type))
			return (t);
	return (NULL);
}

static bool	push_obj(t_parse_obj *p, t_obj *obj,
				t_parse_obj_t const *obj_t, t_vector *pts)
{
	t_vec3 *const	tmp = ft_vpush(pts, NULL, obj_t->bound_len * 3);
	uint32_t		i;

	obj->type->ray_intersect = obj_t->ray_intersect;
	obj->material = p->material;
	p->rot = VEC3_MUL1(p->rot, M_PI/2.f);
	obj->m = ft_mat4transform(p->pos, p->rot, p->shear, p->scale);
	obj->m_inv = ft_mat4transform_inv(p->pos, p->rot, p->shear, p->scale);
	if (obj->material.texture == NULL)
		obj->material.texture = load_texture1(p->color);
	if (obj->material.specular_map == NULL)
		obj->material.specular_map = load_texture1(p->specular_color);
	ft_memcpy(tmp, obj_t->bounds, S(t_vec3, obj_t->bound_len));
	i = 0;
	while (i < obj_t->bound_len)
		ft_mat4apply_vec3(&obj->m, &tmp[i++], 1.f);
	return (true);
}

bool		parse_obj(t_xml_parser *xml, t_obj **obj, t_vector *pts)
{
	t_parse_obj_t const *const	obj_t = get_obj_t(ft_xml_name(xml));
	t_parse_obj					p;

	if (obj_t == NULL)
		return (ft_xml_error(xml, SUBC("Unknown object")));
	*obj = MALLOC(sizeof(t_obj) + obj_t->extra_size);
	p = (t_parse_obj){DEF_MTL, 0, 0xFFFFFF, VEC3_0(), VEC3_0(),
		VEC3_0(), VEC3_1(1.f)};
	while (ft_xml_next(xml))
		if (xml->token == XML_TOKEN_START)
		{
			if (!obj_t->parse_child(xml, *obj))
				return (free(*obj), false);
		}
		else if (xml->token == XML_TOKEN_PARAM)
		{
			if (!parse_xml_param(xml, &g_obj_params, &p)
				&& (xml->token == XML_TOKEN_ERROR
					|| !obj_t->parse_param(xml, *obj)))
					return (free(*obj), false);
		}
		else
			ASSERT(xml->token == XML_TOKEN_PARAM);
	if (xml->token != XML_TOKEN_END)
		return (free(*obj), false);
	return (push_obj(&p, *obj, obj_t, pts));
}

bool		parse_scene_obj(t_xml_parser *xml, t_parse_scene *scene)
{
	t_obj		*obj;

	if (!parse_obj(xml, &obj, &scene->kdtree.pts))
		return (false);
	kdtree_builder_push(&scene->kdtree, obj);
	return (true);
}
