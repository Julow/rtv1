/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:08:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 16:35:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_win.h"
#include <mlx.h>

bool		ft_mlx_open(t_mlx_win *dst, void *mlx, t_vec2u size, t_sub title)
{
	char			title_buff[title.length + 1];
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	ft_memcpy(title_buff, title.str, title.length);
	title_buff[title.length] = '\0';
	dst->mlx_context = mlx;
	if ((dst->win_id = mlx_new_window(mlx, size.x, size.y, title_buff)) == NULL)
		return (false);
	if ((dst->img_id = mlx_new_image(mlx, size.x, size.y)) == NULL)
	{
		mlx_destroy_window(dst->mlx_context, dst->win_id);
		return (false);
	}
	dst->img = (t_img){V(mlx_get_data_addr(dst->img_id, &bits_per_pixel,
					&size_line, &endian)), size.x, size.y};
	if (bits_per_pixel != 32 || endian != 0)
	{
		ft_mlx_close(dst);
		return (false);
	}
	return (true);
}
