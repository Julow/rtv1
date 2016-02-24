/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:17:51 by juloo             #+#    #+#             */
/*   Updated: 2016/02/24 19:25:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H

# include "ft/libft.h"
# include "ft/math.h"

/*
** ========================================================================== **
** Color utils
** -
** color_fto24		3 floats to 24 bits
** color_fto32		4 floats to 32 bits
** color_24tof		24 bits to 3 floats
** color_sto32		hex string to 32 bits
*/

uint32_t		color_fto24(t_vec3 color);
uint32_t		color_fto32(t_vec4 color);
t_vec3			color_24tof(uint32_t color);

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

#endif
