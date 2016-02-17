/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:36:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 18:43:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"

#include "main.h"
#include "mlx_win.h"

#include <mlx.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Transform
*/

typedef struct s_transform		t_transform;

struct			s_transform
{
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	t_vec3			scale;
};

/*
** ========================================================================== **
** Obj
*/

/*
** ?enum obj_type
** char const		*name;
** bool			(*ray_collide)(t_ray const *ray);
** float		(*ray_dist)(t_ray const *ray);
** LIGHT(?name?, NULL, NULL)
** SPHERE(?name?, NULL, NULL)
** PLANE(?name?, NULL, NULL)
*/

struct			s_evalue_obj_type
{
	char const		*name;
	bool			(*ray_collide)(t_ray const *ray);
};

typedef struct s_evalue_obj_type const*		t_obj_type;

struct			s_enum_obj_type
{
	t_obj_type			LIGHT;
	t_obj_type			SPHERE;
	t_obj_type			PLANE;
	int					length;
	t_obj_type const	*values;
};

extern struct s_enum_obj_type const		g_obj_type;

/*
** ?end
*/

/*
** ?enum-def obj_type
*/

struct s_enum_obj_type const	g_obj_type = {
	&(struct s_evalue_obj_type){LIGHT, NULL},
	&(struct s_evalue_obj_type){SPHERE, NULL},
	&(struct s_evalue_obj_type){PLANE, NULL},
	3,
	(t_obj_type const*)&g_obj_type
};

/*
** ?end
*/

typedef struct s_obj		t_obj;

struct			s_obj
{
	t_obj_type		type;
	t_transform		transform;
	t_mat4			model;
	t_mat4			model_inv;
};

/*
** ========================================================================== **
** Scene
*/

typedef struct s_scene		t_scene;

struct			s_scene
{
	t_vector		objs;
	t_vec3			sky_color;
	t_vec3			sky_light;
};

/*
** ========================================================================== **
** Raytracer
*/

typedef struct s_ray		t_ray;
typedef struct s_ray_res	t_ray_res;

struct			s_ray
{
	t_mat4			matrix;
};

struct			s_ray_res
{
	t_vec3			color;
	float			light;
};

t_ray_res		ray_trace(t_scene const *scene, t_ray const *ray);

/*
** ========================================================================== **
** Main
*/

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
