/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 21:02:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_printf.h"
#include "ft/ft_vector.h"
#include "ft/libft.h"
#include "ft/thread_pool.h"

#include "math_utils.h"
#include "mlx_win.h"
#include "obj_types.h"
#include "scene.h"
#include "scene_loader.h"
#include "scene_render_manager.h"
#include "scene_renderer.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Main
** -
** TODO: directional light
** TODO: post-process/texture filter
** TODO: gradient texture
*/

typedef struct s_main		t_main;

# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# define WIN_TITLE		"rtv1"

struct			s_main
{
	t_thread_pool	*thread_pool;
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
# define KEYCODE_R		15
# define KEYCODE_RIGHT	124
# define KEYCODE_LEFT	123
# define KEYCODE_UP		126
# define KEYCODE_DOWN	125

#else

# define KEYCODE_ESC	65307
# define KEYCODE_Q		113
# define KEYCODE_R		114
# define KEYCODE_RIGHT	65363
# define KEYCODE_LEFT	65361
# define KEYCODE_UP		65362
# define KEYCODE_DOWN	65364

#endif

static void		render(t_main *main, uint32_t scene, uint32_t camera)
{
	uint32_t		tmp;

	main->current_scene = (scene + main->scenes.length) % main->scenes.length;
	tmp = VGET(t_scene, main->scenes, main->current_scene).cameras.length;
	main->current_camera = (camera + tmp) % tmp;
	mlx_clear_window(main->mlx, main->win.win_id);
	mlx_string_put(main->mlx, main->win.win_id, 15, 25, 0xFF0000, "Loading...");
	main->should_render = true;
}

static int		key_hook(int keycode, t_main *main)
{
	if (keycode == KEYCODE_ESC || keycode == KEYCODE_Q)
		main_destroy(main);
	else if (keycode == KEYCODE_LEFT && main->scenes.length > 1)
		render(main, main->current_scene - 1, 0);
	else if (keycode == KEYCODE_RIGHT && main->scenes.length > 1)
		render(main, main->current_scene + 1, 0);
	else if (keycode == KEYCODE_UP
		&& VGETC(t_scene, main->scenes, main->current_scene).cameras.length > 1)
		render(main, main->current_scene, main->current_camera + 1);
	else if (keycode == KEYCODE_DOWN
		&& VGETC(t_scene, main->scenes, main->current_scene).cameras.length > 1)
		render(main, main->current_scene, main->current_camera - 1);
	else if (keycode == KEYCODE_R)
		render(main, main->current_scene, main->current_camera);
	return (0);
}

// TODO: make them configs
#define CHUNK_SIZE		VEC2U(64, 75)
#define THREAD_COUNT	4

static uint32_t	scene_render_progress(t_scene_render_manager const *m)
{
	uint32_t const	max = m->renderer.dst->width * m->renderer.dst->height;
	uint32_t		p;

	p = m->progress.y * m->renderer.dst->width
		+ m->progress.x * m->chunk_size.y;
	return ((p >= max) ? 100 : p * 100 / max);
}

static void		render_current_scene(t_main *main)
{
	t_scene const		*scene = VECTOR_GET(main->scenes, main->current_scene);
	uint32_t const		camera = main->current_camera;
	t_scene_render_manager	renderer;

	ft_logf(LOG_VERBOSE, "Rendering scene '%ts'", scene->name);
	scene_render_manager(&renderer, CHUNK_SIZE, scene, camera, &main->win.img);
	ft_cstart();

	main->thread_pool->task_manager = V(&renderer);
	ft_thread_pool_notify(main->thread_pool);

	// ft_thread_pool_join(main->thread_pool);
	while (ft_thread_pool_wait(main->thread_pool))
	{
		ft_printf("\r%-100.*c%!", scene_render_progress(&renderer), '#');
	}
	ft_printf("%n");

	ft_thread_pool_lock(main->thread_pool, false);
	ft_logf(LOG_INFO, "Scene '%ts': Camera #%u: Render time: %llu us",
		scene->name, camera, ft_cend());
}

static int		loop_hook(t_main *main)
{
	if (main->should_render)
	{
		render_current_scene(main);
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

	ft_logf_set_enabled(LOG_DEBUG, true);
	ft_logf_set_enabled(LOG_VERBOSE, true);
	main = (t_main){
		NULL,
		NULL,
		{},
		VECTOR(t_scene),
		-1,
		-1,
		false,
	};
	if ((main.thread_pool = ft_thread_pool_create(THREAD_COUNT)) == NULL)
		return (ft_dprintf(2, "Failed to create threads"), 1);
	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);

	i = 0;
	while (++i < argc)
	{
		ft_logf(LOG_VERBOSE, "Loading scene file: %s", argv[i]);
		if (!load_scenes(argv[i], &main.scenes))
			return (1);
	}

	if (main.scenes.length == 0)
	{
		ft_logf(LOG_ERROR, "No scene loaded");
		return (1);
	}
	ft_logf(LOG_SUCCESS, "%d scene(s) loaded", main.scenes.length);

	mlx_loop_hook(main.mlx, &loop_hook, &main);
	mlx_key_hook(main.win.win_id, &key_hook, &main);
	mlx_expose_hook(main.win.win_id, &expose_hook, &main);

	render(&main, 0, 0);

	mlx_loop(main.mlx);

	ASSERT(false);
	main_destroy(&main);
	return (0);
}
