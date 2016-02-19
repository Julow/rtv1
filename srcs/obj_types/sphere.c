/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/19 15:08:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"

#include "math_utils.h"
#include "obj_types.h"

#include <math.h>

static bool		sphere_ray_intersect(t_vertex *intersect, t_sphere const *obj,
					t_vertex const *ray)
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			tmp;
	t_vec3			ray_rel = VEC3_SUB(ray->pos, obj->pos);

	a = ft_vec3dot(ray->dir, ray->dir);
	b = ft_vec3dot(ray_rel, ray->dir) * 2;
	c = ft_vec3dot(ray_rel, ray_rel) - (obj->radius * obj->radius);
	d = b * b - (4 * a * c);
	if (d == 0.f)
		tmp = -b / (2.f * a);
	else if (d < 0.f || ((tmp = (-b - sqrt(d)) / (2.f * a)) < 0.f
			&& (tmp = (-b + sqrt(d)) / (2.f * a)) < 0.f))
		return (false);
	intersect->pos = VEC3_ADD(ray->pos, VEC3_MUL1(ray->dir, tmp));
	intersect->dir = VEC3_DIV1(VEC3_SUB(intersect->pos, obj->pos), obj->radius);
	return (true);
}

t_sphere			*sphere_new(void)
{
	static t_obj_class const	sphere_class = {
		SUBC("sphere"),
		V(&sphere_ray_intersect),
	};
	t_sphere *const				sphere = NEW(t_sphere);

	ft_bzero(sphere, sizeof(t_sphere));
	sphere->obj.type = &sphere_class;
	return (sphere);
}
