/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 14:24:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "main.h"
#include "mlx_win.h"

#include <mlx.h>
#include <stdlib.h>

static void		main_destroy(t_main *main)
{
	ft_mlx_close(&main->win);
	exit(0);
}

static int		key_hook(int keycode, t_main *main)
{
	if (keycode == 53 || keycode == 12)
		main_destroy(main);
	return (0);
}

int				main(void)
{
	t_main			main;

	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);
	mlx_key_hook(main.win.win_id, &key_hook, &main);
	ft_mlx_update(&main.win);
	mlx_loop(main.mlx);
	ASSERT(false);
	main_destroy(&main);
	return (0);
}
