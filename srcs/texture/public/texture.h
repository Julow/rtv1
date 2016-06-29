/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 00:14:16 by juloo             #+#    #+#             */
/*   Updated: 2016/06/29 15:43:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "ft/img.h"
# include "ft/libft.h"
# include "ft/math_vec2.h"
# include "ft/math_vec4.h"

typedef struct s_texture		t_texture;

/*
** ========================================================================== **
** Texture
*/

struct			s_texture
{
	t_vec4			(*get)(t_texture const *texture, t_vec2 p);
	t_img			img;
};

# define TEXTURE(F)			((t_texture){(F), IMG()})

# define TEXTURE_GET(T, UV)	((T)->get((T), (UV)))

/*
** ========================================================================== **
** some texture->get functions
*/

t_vec4			texture_solid(t_texture const *texture, t_vec2 uv);
t_vec4			texture_nearest(t_texture const *texture, t_vec2 uv);
t_vec4			texture_bilinear(t_texture const *texture, t_vec2 uv);

#endif
