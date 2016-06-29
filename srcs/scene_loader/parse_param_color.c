/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 19:05:22 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 19:15:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

#include "internal.h"
#include "texture_loader.h"

static bool	parse_color_hex(t_sub value, t_texture const **dst, uint32_t flags)
{
	uint32_t	color;

	if (!color_hex(ft_subtrim_is(value, IS_SPACE), &color))
		return (false);
	*dst = load_texture1(color, flags);
	return (true);
}

static bool	parse_color_map(t_sub value, t_texture const **dst, uint32_t flags)
{
	value = ft_subtrim_is(value, IS_SPACE);
	return ((*dst = load_texture(value, flags)) != NULL);
}

static t_parse_color const	g_parse_color[] = {
	{SUBC("#"), &parse_color_hex},
	{SUBC("map:"), &parse_color_map},
};

static bool	parse_color_(t_sub value, t_texture const **dst, uint32_t flags)
{
	t_parse_color const	*c;

	c = g_parse_color;
	while (V(c) < ENDOF(&g_parse_color))
	{
		if (c->name.length <= value.length
				&& ft_memcmp(c->name.str, value.str, c->name.length) == 0)
			return (c->f(SUB_FOR(value, c->name.length), dst, flags));
		c++;
	}
	return (false);
}

bool		parse_color(t_sub value, t_texture const **dst)
{
	return (parse_color_(value, dst, 0));
}

bool		parse_color_g(t_sub value, t_texture const **dst)
{
	return (parse_color_(value, dst, TEXTURE_GAMMA));
}
