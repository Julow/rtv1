/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:40:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/14 17:18:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/img_loader.h"

#include "texture_loader.h"

#include <stdlib.h>

static t_hmap	*texture_cache(void)
{
	static t_hmap	*cache = NULL;

	if (cache == NULL)
		cache = ft_hmapnew(15, &ft_djb2);
	return (cache);
}

t_img const		*load_texture(t_sub file_name)
{
	t_hmap *const	cache = texture_cache();
	t_hpair			tmp;

	if ((tmp = ft_hmapget(cache, file_name)).key != NULL)
		return (tmp.value);
	tmp = ft_hmapput(cache, file_name, NULL, sizeof(t_img));
	if (!ft_load_img(tmp.key, tmp.value))
	{
		ft_hmaprem(cache, file_name, NULL);
		return (NULL);
	}
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
	*tmp = (t_img){ENDOF(tmp), 1, 1};
	*tmp->data = color;
	return (tmp);
}
