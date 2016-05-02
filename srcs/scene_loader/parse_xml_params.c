/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xml_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 10:28:44 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/02 16:26:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/set.h"
#include "internal.h"

struct		s_param
{
	t_set_h		set_h;
	t_sub		name;
};

static bool	parse_xml_param(t_xml_parser *xml, t_vector const *defs, void *data)
{
	t_sub const			param = ft_xml_name(xml);
	t_sub const			value = ft_xml_value(xml);
	uint32_t			i;
	t_param_def const	*def;

	i = 0;
	while (i < defs->length)
	{
		def = VECTOR_GET(*defs, i++);
		if (SUB_EQU(def->name, param))
			return (def->parse(value, data + def->offset)
				|| ft_xml_error(xml, SUBC("Invalid value")));
	}
	return (ft_xml_error(xml, SUBC("Invalid param")));
}

static int	param_cmp(struct s_param const *a, t_sub const *b)
{
	if (a->name.length != b->length)
		return (a->name.length - b->length);
	return (ft_memcmp(a->name.str, b->str, b->length));
}

static bool	parse_xml_params_loop(t_xml_parser *xml, t_set *prev_params,
				t_vector const *defs, void *data)
{
	t_sub const		p = ft_xml_name(xml);
	char			param_name[p.length];
	struct s_param	param;

	ft_memcpy(param_name, p.str, p.length);
	param = (struct s_param){SET_H(), SUB(param_name, p.length)};
	if ((ft_set_cget(prev_params, &param.name) != NULL
		&& !ft_xml_error(xml, SUBC("Redefined param")))
		|| !parse_xml_param(xml, defs, data))
	{
		ft_dstradd(&xml->tmp_str, SUBC(": "));
		ft_dstradd(&xml->tmp_str, param.name);
		ft_dstradd(&xml->tmp_str, SUBC("=\"...\""));
		return (false);
	}
	if (!ft_xml_next(xml) || xml->token != XML_TOKEN_PARAM)
		return (true);
	ASSERT(ft_set_insert(prev_params, &param, &param.name));
	return (parse_xml_params_loop(xml, prev_params, defs, data));
}

bool		parse_xml_params(t_xml_parser *xml,
				t_vector const *defs, void *data)
{
	t_set		prev_params;

	prev_params = SET(param_cmp, 0);
	return (xml->token != XML_TOKEN_PARAM
		|| parse_xml_params_loop(xml, &prev_params, defs, data));
}
