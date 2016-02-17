/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:08:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 13:31:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_win.h"
#include <mlx.h>

void			ft_mlx_close(t_mlx_win *win)
{
	mlx_destroy_window(win->mlx_context, win->win_id);
	mlx_destroy_image(win->mlx_context, win->img_id);
}
