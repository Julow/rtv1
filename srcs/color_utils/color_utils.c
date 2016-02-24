/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:26:15 by juloo             #+#    #+#             */
/*   Updated: 2016/02/24 19:26:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"

t_vec3			color_24tof(uint32_t color)
{
	return (VEC3(
		((float)((color >> 16) & 0xFF)) / 256.f,
		((float)((color >> 8) & 0xFF)) / 256.f,
		((float)((color >> 0) & 0xFF)) / 256.f
	));
}

uint32_t		color_fto24(t_vec3 color)
{
	return (
		  (((uint8_t)(color.x * 255.f)) << 16)
		| (((uint8_t)(color.y * 255.f)) << 8)
		| (((uint8_t)(color.z * 255.f)) << 0)
	);
}

uint32_t		color_fto32(t_vec4 color)
{
	return (
		  (((uint8_t)(color.w * 255.f)) << 24)
		| (((uint8_t)(color.x * 255.f)) << 16)
		| (((uint8_t)(color.y * 255.f)) << 8)
		| (((uint8_t)(color.z * 255.f)) << 0)
	);
}
