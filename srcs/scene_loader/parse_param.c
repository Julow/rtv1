/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:13:37 by juloo             #+#    #+#             */
/*   Updated: 2016/02/24 19:28:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"
#include "internal.h"

t_sub		ft_subtrim_is(t_sub sub, t_is is)
{
	while (sub.length > 0 && IS(sub.str[0], is))
		sub = SUB_FOR(sub, 1);
	while (sub.length > 0 && IS(sub.str[sub.length - 1], is))
		sub.length--;
	return (sub);
}

bool		parse_name(t_sub value, t_dstr *dst)
{
	if (value.length > 0 && ft_subfind_is(value, ~IS_PRINT, 0) < value.length)
		return (false);
	dst->length = 0;
	ft_dstradd(dst, value);
	return (true);
}

bool		parse_vec3(t_sub value, t_vec3 *dst)
{
	t_sub		f;

	f = SUB_START(value);
	if (ft_subnext_c(value, &f, ',')
		&& parse_float(f, &dst->x)
		&& ft_subnext_c(value, &f, ',')
		&& parse_float(f, &dst->y)
		&& ft_subnext_c(value, &f, ',')
		&& parse_float(f, &dst->z)
		&& !ft_subnext_c(value, &f, ','))
		return (true);
	if (parse_float(value, &dst->x))
	{
		dst->y = dst->x;
		dst->z = dst->x;
		return (true);
	}
	return (false);
}

uint32_t	subto_uint_bi(t_sub sub, uint32_t *dst, t_sub base)
{
	uint32_t		i;
	uint32_t		n;
	uint32_t		tmp;

	i = 0;
	n = 0;
	while (i < sub.length
		&& (tmp = ft_subfind_c(base, LOWER(sub.str[i]), 0)) < base.length)
	{
		n = n * base.length + tmp;
		i++;
	}
	*dst = n;
	return (i);
}

bool		parse_color(t_sub value, t_vec3 *dst)
{
	uint32_t	color;

	value = ft_subtrim_is(value, IS_SPACE);
	if (value.length > 0 && value.str[0] == '#')
		value = SUB_FOR(value, 1);
	if (subto_uint_bi(value, &color, SUBC("0123456789abcdef")) < value.length)
		return (false);
	*dst = color_24tof(color);
	return (true);
}

bool		parse_float(t_sub value, float *dst)
{
	value = ft_subtrim_is(value, IS_SPACE);
	if (ft_subto_float(value, dst) < value.length)
		return (false);
	return (true);
}

bool		parse_param(t_vector const *defs, void *data,
					t_sub param, t_sub value)
{
	uint32_t			i;
	t_param_def const	*def;

	i = 0;
	while (i < defs->length)
	{
		def = VECTOR_GET(*defs, i++);
		if (SUB_EQU(def->name, param))
			return (def->parse(value, data + def->offset));
	}
	return (false);
}
