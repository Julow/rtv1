/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 00:45:21 by juloo             #+#    #+#             */
/*   Updated: 2016/06/25 01:43:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
#include "texture.h"

#include <math.h>

t_vec4			texture_solid(t_texture const *texture, t_vec2 uv)
{
	return (COLOR_32TOF(IMG_PIXEL(texture->img, 0, 0)));
	(void)uv;
}

t_vec4			texture_nearest(t_texture const *texture, t_vec2 uv)
{
	uv = VEC2(fmod(ABS(uv.x), 1.f) * texture->img.width,
		fmod(ABS(uv.y), 1.f) * texture->img.height);
	return (COLOR_32TOF(IMG_PIXEL(texture->img, (uint32_t)uv.x, (uint32_t)uv.y)));
}

#define TEXTURE_F(T,P,X,Y)	(COLOR_32TOF(IMG_PIXEL((T)->img, (P)[X].x, (P)[Y].y)))

t_vec4			texture_bilinear(t_texture const *texture, t_vec2 uv)
{
	t_vec2i			p[2];

	uv = VEC2(fmod(ABS(uv.x), 1.f) * texture->img.width - 0.5f,
		fmod(ABS(uv.y), 1.f) * texture->img.height - 0.5f);
	p[0] = VEC2I(uv.x, uv.y);
	uv = VEC2(uv.x - p[0].x, uv.y - p[0].y);
	if (p[0].x < 0)
		p[0].x = texture->img.width - 1;
	if (p[0].y < 0)
		p[0].y = texture->img.height - 1;
	p[1] = VEC2I((p[0].x + 1) % texture->img.width,
		(p[0].y + 1) % texture->img.height);
	return (VEC4_ADD(VEC4_MUL1(VEC4_ADD(
			VEC4_MUL1(TEXTURE_F(texture, p, 0, 0), 1.f - uv.x),
			VEC4_MUL1(TEXTURE_F(texture, p, 1, 0), uv.x)), 1.f - uv.y),
		VEC4_MUL1(VEC4_ADD(VEC4_MUL1(TEXTURE_F(texture, p, 0, 1), 1.f - uv.x),
			VEC4_MUL1(TEXTURE_F(texture, p, 1, 1), uv.x)), uv.y)));
}
