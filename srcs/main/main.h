/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:45:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 14:03:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft/libft.h"
# include "mlx_win.h"

typedef struct s_main		t_main;

/*
** ========================================================================== **
*/

# define WIN_WIDTH		800
# define WIN_HEIGHT		450

# define WIN_TITLE		"rtv1"

struct			s_main
{
	void			*mlx;
	t_mlx_win		win;
};

#endif
