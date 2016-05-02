/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:08:01 by juloo             #+#    #+#             */
/*   Updated: 2016/05/02 10:59:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/ft_dstr.h"
# include "ft/ft_xml.h"
# include "ft/libft.h"

# include "kd_tree_builder.h"
# include "obj.h"
# include "scene.h"
# include "scene_loader.h"

typedef struct s_parse_scene	t_parse_scene;
typedef struct s_scene_child	t_scene_child;

typedef struct s_parse_obj		t_parse_obj;
typedef struct s_parse_obj_t	t_parse_obj_t;

typedef struct s_param_def		t_param_def;

/*
** ========================================================================== **
** Parse
*/

struct		s_parse_scene
{
	t_dstr				name;
	t_kdtree_builder	kdtree;
	t_vector			lights;
	t_vector			cameras;
	t_vec3				sky_color;
};

struct		s_scene_child
{
	t_sub		name;
	bool		(*parse)(t_xml_parser *xml, t_parse_scene *scene);
};

bool		parse_scene_light(t_xml_parser *xml, t_parse_scene *scene);
bool		parse_scene_camera(t_xml_parser *xml, t_parse_scene *scene);

/*
** ========================================================================== **
** Parse obj
*/

struct		s_parse_obj
{
	t_material		material;
	uint32_t		color;
	uint32_t		specular_color;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	t_vec3			scale;
	t_obj			*obj;
	t_vector		*pts;
};

struct		s_parse_obj_t
{
	t_sub			name;
	bool			(*parse_obj)(t_xml_parser *xml, t_parse_obj *p);
	t_intersect_f	ray_intersect;
	uint32_t		extra_size;
	t_vec3 const	*bounds;
	uint32_t		bound_len;
};

bool		parse_obj(t_xml_parser *xml, t_obj **obj, t_vector *pts);

bool		parse_scene_obj(t_xml_parser *xml, t_parse_scene *scene);

bool		parse_obj_default(t_xml_parser *xml, t_parse_obj *p);
bool		parse_obj_csg(t_xml_parser *xml, t_parse_obj *p);

extern t_vector const	g_obj_params;

/*
** ========================================================================== **
** Params
*/

struct		s_param_def
{
	t_sub			name;
	bool			(*parse)(t_sub value, void *dst);
	uint32_t		offset;
};

#define PARAM(NAME,F,S,VAR)		{SUBC(NAME),V(&parse_##F),offsetof(S,VAR)}

/*
** TODO: move
*/
bool		parse_xml_params(t_xml_parser *xml,
				t_vector const *defs, void *data);

bool		parse_vec3(t_sub value, t_vec3 *dst);
bool		parse_color(t_sub value, uint32_t *dst);
bool		parse_colorf(t_sub value, t_vec3 *dst);
bool		parse_texture(t_sub value, t_img const **dst);
bool		parse_texture_g(t_sub value, t_img const **dst);
bool		parse_float(t_sub value, float *dst);
bool		parse_name(t_sub value, t_dstr *dst);

t_sub		ft_subtrim_is(t_sub sub, t_is is);

#endif
