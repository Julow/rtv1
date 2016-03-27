/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:40:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/27 20:23:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/ft_printf.h"
#include "ft/img_loader.h"

#include "color_utils.h"
#include "texture_loader.h"

#include <stdlib.h>

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

t_img const		*load_texture(t_sub file_name)
{
	t_hmap *const	cache = texture_cache();
	t_hpair			tmp;

	if ((tmp = ft_hmapget(cache, file_name)).key != NULL)
	{
		ft_logf(LOG_DEBUG, "Cached texture: %ts", file_name);
		return (tmp.value);
	}
	tmp = ft_hmapput(cache, file_name, NULL, sizeof(t_img));
	if (!ft_load_img(tmp.key, tmp.value))
	{
		ft_logf(LOG_VERBOSE, "Failed to load '%ts'", file_name);
		ft_hmaprem(cache, file_name, NULL);
		return (NULL);
	}
	ft_logf(LOG_VERBOSE, "Texture file '%ts' loaded", file_name);
	ft_img_map(tmp.value, &correct_gamma);
	return (tmp.value);
}

t_img const		*load_texture1(uint32_t color)
{
	t_hmap *const	cache = texture_cache();
	t_img			*tmp;

	if ((tmp = ft_hmapget(cache, SUB(V(&color), sizeof(uint32_t))).value) != NULL)
		return (tmp);
	tmp = ft_hmapput(cache, SUB(V(&color), sizeof(uint32_t)), NULL,
			sizeof(t_img) + sizeof(uint32_t)).value;
	ft_logf(LOG_DEBUG, "Solid texture created: #%.8x", color);
	*tmp = (t_img){ENDOF(tmp), 1, 1};
	*tmp->data = correct_gamma(color);
	return (tmp);
}
