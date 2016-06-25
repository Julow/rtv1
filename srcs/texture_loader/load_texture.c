/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:40:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/25 23:56:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"
#include "ft/ft_hmap.h"
#include "ft/ft_printf.h"
#include "ft/img_loader.h"

#include "texture.h"
#include "texture_loader.h"

#include <stdlib.h>

/*
** TODO: move
*/
#define SUBV(V)		SUB((char const*)(V), sizeof(V))

static t_hmap	*texture_cache(void)
{
	static t_hmap	*cache = NULL;

	if (cache == NULL)
		cache = ft_hmapnew(15, &ft_djb2);
	return (cache);
}

t_texture const	*load_texture(t_sub file_name, uint32_t flags)
{
	t_hmap *const	cache = texture_cache();
	char			key[sizeof(uint32_t) + file_name.length];
	t_texture		*texture;

	*(uint32_t*)key = flags;
	ft_memcpy(key + sizeof(uint32_t), file_name.str, file_name.length);
	if ((texture = ft_hmapget(cache, SUBV(key)).value) != NULL)
	{
		ft_logf(LOG_DEBUG, "Cached texture: %ts", file_name);
		return (texture);
	}
	texture = ft_hmapput(cache, SUBV(key), NULL, sizeof(t_texture)).value;
	texture->get = &texture_bilinear;
	if (!ft_load_img(file_name, &texture->img))
	{
		ft_logf(LOG_VERBOSE, "Failed to load '%ts'", file_name);
		ft_hmaprem(cache, SUBV(key), NULL);
		return (NULL);
	}
	if (flags & TEXTURE_GAMMA)
		correct_gamma(&texture->img);
	ft_logf(LOG_VERBOSE, "Texture file '%ts' loaded", file_name);
	return (texture);
}

t_texture const	*load_texture1(uint32_t color, uint32_t flags)
{
	t_hmap *const	cache = texture_cache();
	uint32_t		key[2];
	t_texture		*tmp;

	key[0] = flags;
	key[1] = color;
	if ((tmp = ft_hmapget(cache, SUBV(key)).value) != NULL)
		return (tmp);
	tmp = ft_hmapput(cache, SUBV(key), NULL,
		sizeof(t_texture) + sizeof(uint32_t)).value;
	ft_logf(LOG_DEBUG, "Solid texture created: #%.8x", color);
	*tmp = (t_texture){&texture_solid, (t_img){ENDOF(tmp), 1, 1}};
	*tmp->img.data = color;
	if (flags & TEXTURE_GAMMA)
		correct_gamma(&tmp->img);
	return (tmp);
}
