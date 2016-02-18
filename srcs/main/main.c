/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/18 20:14:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/ft_vector.h"
#include "ft/libft.h"
#include "ft/math.h"

#include "camera.h"
#include "math_utils.h"
#include "mlx_win.h"
#include "obj_sphere.h"
#include "scene.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Main
*/

typedef struct s_main		t_main;

# define WIN_WIDTH		800
# define WIN_HEIGHT		450

# define WIN_TITLE		"rtv1"

struct			s_main
{
	void			*mlx;
	t_mlx_win		win;
	t_scene			scene;
	t_camera		camera;
};

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

static int		expose_hook(t_main *main)
{
	ft_mlx_update(&main->win);
	return (0);
}

int				main(void)
{
	t_main			main;

	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);
	main.scene = (t_scene){VECTOR(t_obj*), VEC3(0.5f, 0.95f, 1.f)};
	main.camera = (t_camera){VEC3(0.f, 0.f, -5.f), VEC3(0.f, 0.f, 1.f), 100.f};

	mlx_key_hook(main.win.win_id, &key_hook, &main);
	mlx_expose_hook(main.win.win_id, &expose_hook, &main);

	t_sphere		*obj;

	obj = sphere_new();
	obj->obj.color = VEC4(1.f, 0.2f, 0.2f, 1.f);
	obj->radius = 2.f;
	ft_vpush(&main.scene.objs, V(&obj), 1);

	obj = sphere_new();
	obj->obj.color = VEC4(0.2f, 1.f, 0.2f, 1.f);
	obj->radius = 2.f;
	obj->pos = VEC3(1.5f, 0.f, 0.f);
	ft_vpush(&main.scene.objs, V(&obj), 1);

	camera_render(&main.win.img, &main.camera, &main.scene);

	mlx_loop(main.mlx);
	ASSERT(false);
	main_destroy(&main);
	return (0);
}
