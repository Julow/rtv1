/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:40:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/14 12:07:27 by jaguillo         ###   ########.fr       */
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

static void		img_clear(t_img *img)
{
	free(img->data);
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

void			unload_texture(t_sub file_name)
{
	ft_hmaprem(texture_cache(), file_name, V(&img_clear));
}
