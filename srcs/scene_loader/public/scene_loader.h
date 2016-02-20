/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 20:47:17 by juloo             #+#    #+#             */
/*   Updated: 2016/02/20 20:50:18 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LOADER_H
# define SCENE_LOADER_H

# include "scene.h"

/*
** Load scenes from a XML file
** Return false on error
** -
** Push loaded scenes to 'dst'
*/
bool		load_scenes(t_sub file, t_vector *dst);

#endif
