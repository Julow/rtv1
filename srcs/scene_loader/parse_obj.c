/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:51:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 19:12:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "obj_types.h"
#include "texture_loader.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

t_vector const			g_obj_params = VECTOR(t_param_def,
	PARAM("color", color_g, t_parse_obj, material.texture),
	PARAM("specular", color_g, t_parse_obj, material.specular_map),
	PARAM("normal", color, t_parse_obj, material.normal_map),
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
	{SUBC("sphere"), &parse_obj_default,
		{&sphere_ray_intersect}, 0, g_bounds_cube, 8},
	{SUBC("plane"), &parse_obj_default, {&plane_ray_intersect}, 0,
		(t_vec3[]){
			{-0.5f, 0.f, -0.5f},
			{-0.5f, 0.f, 0.5f},
			{0.5f, 0.f, 0.5f},
			{0.5f, 0.f, -0.5f},
		}, 4},
	{SUBC("cylinder"), &parse_obj_default,
		{&cylinder_ray_intersect}, 0, g_bounds_cube, 8},
	{SUBC("cone"), &parse_obj_default, {&cone_ray_intersect}, 0,
		(t_vec3[]){
			{0.f, 0.f, 0.f},
			{-1.f, 1.f, -1.f},
			{1.f, 1.f, -1.f},
			{1.f, -1.f, -1.f},
			{-1.f, -1.f, -1.f},
		}, 5},
	{SUBC("or"), &parse_obj_csg, {&or_ray_intersect}, S(t_obj*, 2), NULL, 0},
	{SUBC("not"), &parse_obj_csg, {&not_ray_intersect}, S(t_obj*, 2), NULL, 0},
	{SUBC("and"), &parse_obj_csg, {&and_ray_intersect}, S(t_obj*, 2), NULL, 0},
);

static t_parse_obj_t const	*get_obj_t(t_sub obj_type)
{
	t_parse_obj_t const	*t;

	t = VECTOR_IT(g_parse_objs);
	while (VECTOR_NEXT(g_parse_objs, t))
		if (SUB_EQU(t->name, obj_type))
			return (t);
	return (NULL);
}

static bool	push_obj(t_parse_obj *p, t_parse_obj_t const *obj_t)
{
	t_vec3 *const	tmp = ft_vpush(p->pts, NULL, obj_t->bound_len * 3);
	uint32_t		i;

	p->obj->type = &obj_t->obj_type;
	p->obj->material = p->material;
	p->rot = VEC3_MUL1(p->rot, M_PI/2.f);
	p->obj->m = ft_mat4transform(p->pos, p->rot, p->shear, p->scale);
	p->obj->m_inv = ft_mat4transform_inv(p->pos, p->rot, p->shear, p->scale);
	if (p->obj->material.texture == NULL)
		p->obj->material.texture = load_texture1(DEFAULT_COLOR, TEXTURE_GAMMA);
	if (p->obj->material.specular_map == NULL)
		p->obj->material.specular_map = load_texture1(DEFAULT_SPECULAR, 0);
	ft_memcpy(tmp, obj_t->bounds, S(t_vec3, obj_t->bound_len));
	i = 0;
	while (i < obj_t->bound_len)
		ft_mat4apply_vec3(&p->obj->m, &tmp[i++], 1.f);
	return (true);
}

bool		parse_obj(t_xml_parser *xml, t_obj **obj, t_vector *pts)
{
	t_parse_obj_t const *const	obj_t = get_obj_t(ft_xml_name(xml));
	t_parse_obj					p;

	if (obj_t == NULL)
		return (ft_xml_error(xml, SUBC("Unknown object")));
	*obj = MALLOC(sizeof(t_obj) + obj_t->extra_size);
	ft_bzero(*obj, sizeof(t_obj) + obj_t->extra_size);
	p = (t_parse_obj){DEF_MTL, VEC3_0(), VEC3_0(),
		VEC3_0(), VEC3_1(1.f), *obj, pts};
	if (!obj_t->parse_obj(xml, &p))
		return (free(*obj), false);
	return (push_obj(&p, obj_t));
}
