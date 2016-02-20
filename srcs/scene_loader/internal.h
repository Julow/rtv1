/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:08:01 by juloo             #+#    #+#             */
/*   Updated: 2016/02/20 22:26:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "scene_loader.h"

typedef struct s_param_def	t_param_def;

/*
** ========================================================================== **
*/

struct			s_param_def
{
	t_sub			name;
	bool			(*parse)(t_sub value, void *dst);
	uint32_t		offset;
};

bool			parse_param(t_vector const *defs, void *data,
					t_sub param, t_sub value);

bool			parse_vec3(t_sub value, t_vec3 *dst);
bool			parse_color(t_sub value, t_vec3 *dst);
bool			parse_float(t_sub value, float *dst);

#endif
