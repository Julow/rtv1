/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/14 14:01:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"
#include "ft/ft_vector.h"
#include "ft/libft.h"

#include "math_utils.h"
#include "mlx_win.h"
#include "obj_types.h"
#include "scene.h"
#include "scene_loader.h"
#include "scene_render.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Main
** -
** TODO: ambient brightness
** TODO: gamma
** TODO: specular/bump mapping
** TODO: check invalid values
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
	uint32_t		current_scene;
	uint32_t		current_camera;
	bool			should_render;
};

static void		main_destroy(t_main *main)
{
	ft_mlx_close(&main->win);
	exit(0);
}

#ifdef MAC_OS_MODE

# define KEYCODE_ESC	53
# define KEYCODE_Q		12
# define KEYCODE_RIGHT	124
# define KEYCODE_LEFT	123
# define KEYCODE_UP		126
# define KEYCODE_DOWN	125

#else

# define KEYCODE_ESC	65307
# define KEYCODE_Q		113
# define KEYCODE_RIGHT	65363
# define KEYCODE_LEFT	65361
# define KEYCODE_UP		65362
# define KEYCODE_DOWN	65364

#endif

static void		render_scene(t_main *main, uint32_t scene, uint32_t camera)
{
	uint32_t		tmp;

	scene = (scene + main->scenes.length) % main->scenes.length;
	tmp = VGET(t_scene, main->scenes, scene).cameras.length;
	camera = (camera + tmp) % tmp;
	if (main->current_scene == scene && main->current_camera == camera)
		return ;
	main->current_scene = scene;
	main->current_camera = camera;
	mlx_clear_window(main->mlx, main->win.win_id);
	mlx_string_put(main->mlx, main->win.win_id, 15, 25, 0xFF0000, "Loading...");
	main->should_render = true;
}

static int		key_hook(int keycode, t_main *main)
{
	if (keycode == KEYCODE_ESC || keycode == KEYCODE_Q)
		main_destroy(main);
	else if (keycode == KEYCODE_LEFT && main->scenes.length > 1)
		render_scene(main, main->current_scene - 1, 0);
	else if (keycode == KEYCODE_RIGHT && main->scenes.length > 1)
		render_scene(main, main->current_scene + 1, 0);
	else if (keycode == KEYCODE_UP)
		render_scene(main, main->current_scene, main->current_camera + 1);
	else if (keycode == KEYCODE_DOWN)
		render_scene(main, main->current_scene, main->current_camera - 1);
	return (0);
}

static int		loop_hook(t_main *main)
{
	if (main->should_render)
	{
		ft_cstart();
		scene_render(&main->win.img,
			&VGET(t_scene, main->scenes, main->current_scene),
			main->current_camera);
		ft_printf(C_CYAN "[Info]" C_RESET " Scene #%u: Camera #%u: "
			"Render time: %llu us%n",
			main->current_scene, main->current_camera, ft_cend());
		ft_mlx_update(&main->win);
		main->should_render = false;
	}
	return (0);
}

static int		expose_hook(t_main *main)
{
	if (!main->should_render)
		ft_mlx_update(&main->win);
	return (0);
}

int				main(int argc, char **argv)
{
	int				i;
	t_main			main;

	main = (t_main){
		NULL,
		{},
		VECTOR(t_scene),
		-1,
		-1,
		false,
	};
	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);

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

	mlx_loop_hook(main.mlx, &loop_hook, &main);
	mlx_key_hook(main.win.win_id, &key_hook, &main);
	mlx_expose_hook(main.win.win_id, &expose_hook, &main);

	render_scene(&main, 0, 0);

	mlx_loop(main.mlx);
	ASSERT(false);
	main_destroy(&main);
	return (0);
}
