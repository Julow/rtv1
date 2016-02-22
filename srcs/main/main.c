/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/23 00:57:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"
#include "ft/ft_vector.h"
#include "ft/libft.h"
#include "ft/math.h"

#include "camera.h"
#include "math_utils.h"
#include "mlx_win.h"
#include "obj_types.h"
#include "scene.h"
#include "scene_loader.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Main
** -
** TODO: vector<t_obj*> -> vector<t_obj>
** TODO: specular
** TODO: cylinder/cone
** TODO: refraction critical angle
*/

typedef struct s_main		t_main;

# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# define WIN_TITLE		"rtv1"

struct			s_main
{
	void			*mlx;
	t_mlx_win		win;
	t_vector		scenes;
	t_camera		camera;
};

static void		main_destroy(t_main *main)
{
	ft_mlx_close(&main->win);
	exit(0);
}

// #define KEYCODE_ESC		53
// #define KEYCODE_Q		12

#define KEYCODE_ESC		65307
#define KEYCODE_Q		113

static int		key_hook(int keycode, t_main *main)
{
	if (keycode == KEYCODE_ESC || keycode == KEYCODE_Q)
		main_destroy(main);
	return (0);
}

static int		expose_hook(t_main *main)
{
	ft_mlx_update(&main->win);
	return (0);
}

int				main(int argc, char **argv)
{
	int				i;
	t_main			main;

	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);
	main.scenes = VECTOR(t_scene);
	main.camera = (t_camera){VEC3(0.f, 0.f, -40.f), VEC3(0.f, 0.f, 1.f), 1000.f};

	i = 0;
	while (++i < argc)
		if (!load_scenes(argv[i], &main.scenes))
			return (1);

	if (main.scenes.length == 0)
	{
		ft_dprintf(2, C_RED "[Error]" C_RESET " No scene loaded%n");
		return (1);
	}
	ft_printf(C_CYAN "[Info]" C_RESET " %d scene(s) loaded%n",
		main.scenes.length);

	mlx_key_hook(main.win.win_id, &key_hook, &main);
	mlx_expose_hook(main.win.win_id, &expose_hook, &main);

	ft_cstart();
	camera_render(&main.win.img, &main.camera, &VGET(t_scene, main.scenes, 0));
	ft_printf("Render time: %llu us%n", ft_cend());

	mlx_loop(main.mlx);
	ASSERT(false);
	main_destroy(&main);
	return (0);
}
