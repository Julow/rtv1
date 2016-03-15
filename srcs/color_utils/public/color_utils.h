/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:17:51 by juloo             #+#    #+#             */
/*   Updated: 2016/03/15 11:28:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H

# include "ft/libft.h"
# include "ft/math_vec3.h"
# include "ft/math_vec4.h"

/*
** ========================================================================== **
** Color utils
** -
** color_fto24		3 floats to 24 bits
** color_fto32		4 floats to 32 bits
** color_24tof		24 bits to 3 floats
** color_sto32		hex string to 32 bits
** -
** COLOR_24TOF(C+)	Macro version of color_24tof
** COLOR_FTO24(C+)	Macro version of color_fto24
*/

# define COLOR_24TOF(C)	(VEC3(_24TOF_R(C), _24TOF_G(C), _24TOF_B(C)))
# define COLOR_FTO24(C)	(_FTO24_R((C).x) | _FTO24_G((C).y) | _FTO24_B((C).z))

uint32_t		color_fto24(t_vec3 color);
uint32_t		color_fto32(t_vec4 color);
t_vec3			color_24tof(uint32_t color);

uint32_t		color32_gamma(uint32_t color, float gamma);
t_vec3			colorf_gamma(t_vec3 color, float gamma);

/*
** Convert hex string to 32 bits color
** -
** RGB
** ARGB
** RRGGBB
** AARRGGBB
** -
** 'R', 'G', 'B', 'A' are hex digits
** Default alpha is 'FF'
** Ignore case
*/
// TODO: uint32_t		color_sto32(t_sub str);

/*
** -
** COLOR32_*_MASK		channel mask for 32/24 bits colors
** COLOR32_*_OFFSET		channel offset for 32/24 bits colors
** COLORF_*_FACTOR		factor used to convert from float colors
*/

# define COLOR32_A_MASK		0xFF000000
# define COLOR32_R_MASK		0x00FF0000
# define COLOR32_G_MASK		0x0000FF00
# define COLOR32_B_MASK		0x000000FF

# define COLOR32_A_OFFSET	24
# define COLOR32_R_OFFSET	16
# define COLOR32_G_OFFSET	8
# define COLOR32_B_OFFSET	0

# define COLORF_A_FACTOR	(255.f * 255.f * 255.f * 255.f)
# define COLORF_R_FACTOR	(255.f * 255.f * 255.f)
# define COLORF_G_FACTOR	(255.f * 255.f)
# define COLORF_B_FACTOR	(255.f)

/*
** -
*/

# define _24TOF_R(C)	(((float)((C) & COLOR32_R_MASK)) / COLORF_R_FACTOR)
# define _24TOF_G(C)	(((float)((C) & COLOR32_G_MASK)) / COLORF_G_FACTOR)
# define _24TOF_B(C)	(((float)((C) & COLOR32_B_MASK)) / COLORF_B_FACTOR)

# define _FTO24_R(X)	(((uint32_t)(X * COLORF_R_FACTOR)) & COLOR32_R_MASK)
# define _FTO24_G(Y)	(((uint32_t)(Y * COLORF_G_FACTOR)) & COLOR32_G_MASK)
# define _FTO24_B(Z)	(((uint32_t)(Z * COLORF_B_FACTOR)) & COLOR32_B_MASK)

#endif
