/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:08:18 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 13:31:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_win.h"
#include <mlx.h>

void			ft_mlx_update(t_mlx_win *win)
{
	mlx_put_image_to_window(win->mlx_context, win->win_id, win->img_id, 0, 0);
}
