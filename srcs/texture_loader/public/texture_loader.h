/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:34:50 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/14 11:39:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOADER_H
# define TEXTURE_LOADER_H

# include "ft/img.h"
# include "ft/libft.h"

/*
** ========================================================================== **
** Texture loader
** -
** Cache calls to ft_load_img
*/

/*
** Return a texture or NULL on error
*/
t_img const		*load_texture(t_sub file_name);

/*
** Free a texture
*/
void			unload_texture(t_sub file_name);

#endif
