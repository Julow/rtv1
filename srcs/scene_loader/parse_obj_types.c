/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:53:31 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/02 16:16:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

bool		parse_obj_default(t_xml_parser *xml, t_parse_obj *p)
{
	if (!ft_xml_next(xml) || (xml->token == XML_TOKEN_PARAM
			&& !parse_xml_params(xml, &g_obj_params, p)))
		return (false);
	if (xml->token == XML_TOKEN_START)
		return (ft_xml_error(xml, SUBC("Can't have child")));
	return (BOOL_OF(xml->token == XML_TOKEN_END));
}

bool		parse_obj_csg(t_xml_parser *xml, t_parse_obj *p)
{
	t_obj **const	objs = ENDOF(p->obj);

	if (!ft_xml_next(xml) || (xml->token == XML_TOKEN_PARAM
			&& !parse_xml_params(xml, &g_obj_params, p)))
		return (false);
	while (true)
	{
		ASSERT(xml->token == XML_TOKEN_START);
		if (objs[0] != NULL && objs[1] != NULL)
			return (ft_xml_error(xml, SUBC("Too many object")));
		if (!parse_obj(xml, &objs[(objs[0] == NULL) ? 0 : 1], p->pts))
			return (false);
		if (!ft_xml_next(xml))
			break ;
	}
	return (BOOL_OF(xml->token == XML_TOKEN_END && (objs[1] != NULL
			|| ft_xml_error(xml, SUBC("2 objects required")))));
}
