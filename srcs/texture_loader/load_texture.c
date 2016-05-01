/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:40:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/01 21:17:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/ft_printf.h"
#include "ft/img_loader.h"

#include "color_utils.h"
#include "texture_loader.h"

#include <stdlib.h>

#define SUBV(V)		SUB((char const*)(V), sizeof(V)) /* TODO: move */

static t_hmap	*texture_cache(void)
{
	static t_hmap	*cache = NULL;

	if (cache == NULL)
		cache = ft_hmapnew(15, &ft_djb2);
	return (cache);
}

static uint32_t	correct_gamma(uint32_t c)
{
	return (color32_gamma(c, 2.2f));
}

t_img const		*load_texture(t_sub file_name, uint32_t flags)
{
	t_hmap *const	cache = texture_cache();
	char			key[sizeof(uint32_t) + file_name.length];
	t_hpair			tmp;

	*(uint32_t*)key = flags;
	ft_memcpy(key + sizeof(uint32_t), file_name.str, file_name.length);
	if ((tmp = ft_hmapget(cache, SUBV(key))).key != NULL)
	{
		ft_logf(LOG_DEBUG, "Cached texture: %ts", file_name);
		return (tmp.value);
	}
	tmp = ft_hmapput(cache, SUBV(key), NULL, sizeof(t_img));
	if (!ft_load_img(tmp.key + sizeof(uint32_t), tmp.value))
	{
		ft_logf(LOG_VERBOSE, "Failed to load '%ts'", file_name);
		ft_hmaprem(cache, SUBV(key), NULL);
		return (NULL);
	}
	ft_logf(LOG_VERBOSE, "Texture file '%ts' loaded", file_name);
	if (flags & TEXTURE_GAMMA)
		ft_img_map(tmp.value, &correct_gamma);
	return (tmp.value);
}

t_img const		*load_texture1(uint32_t color, uint32_t flags)
{
	t_hmap *const	cache = texture_cache();
	uint32_t		key[2];
	t_img			*tmp;

	key[0] = flags;
	key[1] = color;
	if ((tmp = ft_hmapget(cache, SUBV(key)).value) != NULL)
		return (tmp);
	tmp = ft_hmapput(cache, SUBV(key), NULL,
		sizeof(t_img) + sizeof(uint32_t)).value;
	ft_logf(LOG_DEBUG, "Solid texture created: #%.8x", color);
	*tmp = (t_img){ENDOF(tmp), 1, 1};
	*tmp->data = (flags & TEXTURE_GAMMA) ? correct_gamma(color) : color;
	return (tmp);
}
