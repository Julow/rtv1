/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:34:50 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/25 23:57:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOADER_H
# define TEXTURE_LOADER_H

# include "ft/img.h"
# include "ft/libft.h"

# include "texture.h"

/*
** ========================================================================== **
** Texture loader
** -
** Cache calls to ft_load_img
*/

# define TEXTURE_GAMMA		(1 << 1)

/*
** Return a texture or NULL on error
*/
t_texture const	*load_texture(t_sub file_name, uint32_t flags);

/*
** Create a 1 pixel texture
*/
t_texture const	*load_texture1(uint32_t color, uint32_t flags);

/*
** -
*/
// TODO: move
void			correct_gamma(t_img *img);

#endif
