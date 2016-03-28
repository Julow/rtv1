/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:08:01 by juloo             #+#    #+#             */
/*   Updated: 2016/03/28 11:49:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/ft_xml.h"
# include "ft/libft.h"

# include "obj.h"
# include "scene.h"
# include "scene_loader.h"

typedef struct s_param_def	t_param_def;

/*
** ========================================================================== **
** Parse
*/

typedef struct s_parse_obj		t_parse_obj;

struct			s_parse_obj
{
	t_material		material;
	t_obj_csg		**csg;
	uint32_t		color;
	uint32_t		specular_color;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	t_vec3			scale;
};

bool		parse_scene_light(t_xml_parser *xml, t_light *light);
bool		parse_scene_camera(t_xml_parser *xml, t_camera *camera);
bool		parse_scene_obj(t_xml_parser *xml, t_obj *obj);

/*
** ========================================================================== **
** Params
*/

struct			s_param_def
{
	t_sub			name;
	bool			(*parse)(t_sub value, void *dst);
	uint32_t		offset;
};

#define PARAM(NAME,F,S,VAR)		{SUBC(NAME),V(&parse_##F),offsetof(S,VAR)}

bool			parse_param(t_vector const *defs, void *data,
					t_sub param, t_sub value);

bool			parse_vec3(t_sub value, t_vec3 *dst);
bool			parse_color(t_sub value, uint32_t *dst);
bool			parse_colorf(t_sub value, t_vec3 *dst);
bool			parse_texture(t_sub value, t_img const **dst);
bool			parse_float(t_sub value, float *dst);
bool			parse_name(t_sub value, t_dstr *dst);

t_sub			ft_subtrim_is(t_sub sub, t_is is);

#endif
