/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/22 22:29:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/ft_vector.h"
#include "ft/libft.h"
#include "ft/math.h"

#include "camera.h"
#include "math_utils.h"
#include "mlx_win.h"
#include "obj_types.h"
#include "scene.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Main
** -
** TODO: load scene from xml file
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
	t_scene			scene;
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

void			transform_matrix(t_transform const *t, t_mat4 *m, t_mat4 *m_inv)
{
	if (m != NULL)
	{
		*m = MAT4_I();
		ft_mat4translate(m, t->pos);
		ft_mat4scale3(m, t->scale);
		// ft_mat4shear(m, t->shear);
		ft_mat4rotate(m, t->rot);
		// ft_mat4transpose(m);
	}
	if (m_inv != NULL)
	{
		*m_inv = MAT4_I();
		ft_mat4rotate_inv(m_inv, t->rot);
		// ft_mat4shear(m_inv, t->shear);
		ft_mat4scale3(m_inv, VEC3_DIV(VEC3_1(1.f), t->scale));
		ft_mat4translate(m_inv, VEC3_SUB(VEC3_0(), t->pos));
		// ft_mat4transpose(m_inv);
	}
}

int				main(void)
{
	t_main			main;

	if ((main.mlx = mlx_init()) == NULL || !ft_mlx_open(&main.win, main.mlx,
			VEC2U(WIN_WIDTH, WIN_HEIGHT), SUBC(WIN_TITLE)))
		return (1);
	main.scene = (t_scene){DSTR0(), VECTOR(t_obj*), VECTOR(t_light),
		C(t_material, VEC3(0.f, 0.f, 0.f), 0.f, 0.f, 1.f), VEC3(0.05f, 0.05f, 0.05f)};
	main.camera = (t_camera){VEC3(0.f, 0.f, -40.f), VEC3(0.f, 0.f, 1.f), 1000.f};

	mlx_key_hook(main.win.win_id, &key_hook, &main);
	mlx_expose_hook(main.win.win_id, &expose_hook, &main);

	t_material		test = C(t_material, VEC3(1.f, 0.2f, 0.2f), 1.f, 0.f, 1.f);

	t_sphere		*sphere;
	t_plane			*plane;

	sphere = sphere_new();
	sphere->obj.material = test;
	transform_matrix(&TRANSFORM(VEC3(0.f, -2.5f, 0.f), VEC3_0(), VEC3_0(), VEC3_1(2.f)),
		&sphere->obj.m, &sphere->obj.m_inv);
	ft_vpush(&main.scene.objs, V(&sphere), 1);

	sphere = sphere_new();
	sphere->obj.material = test;
	sphere->obj.material.color = VEC3(0.2f, 1.f, 0.2f);
	// sphere->obj.material.opacity = 0.1f;
	// sphere->obj.material.reflection = 0.f;
	transform_matrix(&TRANSFORM(VEC3(1.5f, -2.5f, 0.f), VEC3_0(), VEC3_0(), VEC3_1(2.f)),
		&sphere->obj.m, &sphere->obj.m_inv);
	ft_vpush(&main.scene.objs, V(&sphere), 1);

	sphere = sphere_new();
	sphere->obj.material = test;
	sphere->obj.material.color = VEC3(1.f, 1.f, 1.f);
	transform_matrix(&TRANSFORM(VEC3(3.f, 1.f, -2.5f), VEC3_0(), VEC3_0(), VEC3_1(0.5f)),
		&sphere->obj.m, &sphere->obj.m_inv);
	ft_vpush(&main.scene.objs, V(&sphere), 1);

	plane = plane_new();
	plane->obj.material = test;
	plane->obj.material.color = VEC3(0.3f, 0.5f, 0.7f);
	plane->obj.material.opacity = 0.8f;
	plane->obj.material.reflection = 1.f;
	transform_matrix(&TRANSFORM(VEC3(0.f, -5.f, 0.f), VEC3_0(), VEC3_0(), VEC3_1(1.f)),
		&plane->obj.m, &plane->obj.m_inv);
	ft_vpush(&main.scene.objs, V(&plane), 1);

	plane = plane_new();
	plane->obj.material = test;
	plane->obj.material.color = VEC3(0.7f, 0.5f, 0.5f);
	plane->obj.material.opacity = 0.5f;
	plane->obj.material.reflection = 0.2f;
	plane->obj.material.refract_index = 1.33f;
	transform_matrix(&TRANSFORM(VEC3(0.f, -0.007f, 0.f), VEC3_0(), VEC3_0(), VEC3_1(1.f)),
		&plane->obj.m, &plane->obj.m_inv);
	ft_vpush(&main.scene.objs, V(&plane), 1);

	t_light			*light;

	light = ft_vpush(&main.scene.lights, NULL, 1);
	light->light = 1.f;
	light->pos = VEC3(10.f, 5.f, -3.f);

	ft_cstart();
	camera_render(&main.win.img, &main.camera, &main.scene);
	ft_printf("Render time: %llu us%n", ft_cend());

	mlx_loop(main.mlx);
	ASSERT(false);
	main_destroy(&main);
	return (0);
}
