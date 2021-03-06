/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:13:37 by juloo             #+#    #+#             */
/*   Updated: 2016/06/29 19:10:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
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

bool		parse_colorf(t_sub value, t_vec3 *dst)
{
	uint32_t	c;

	if (!color_hex(ft_subtrim_is(value, IS_SPACE), &c))
		return (false);
	*dst = color_24tof(c);
	return (true);
}

bool		parse_float(t_sub value, float *dst)
{
	value = ft_subtrim_is(value, IS_SPACE);
	if (ft_subto_float(value, dst) < value.length)
		return (false);
	return (true);
}
