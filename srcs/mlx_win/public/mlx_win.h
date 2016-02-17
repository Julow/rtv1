/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:45:29 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 13:19:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

# include "ft/img.h"
# include "ft/libft.h"

typedef struct s_mlx_win		t_mlx_win;

/*
** ========================================================================== **
** MLX
*/

struct			s_mlx_win
{
	void			*mlx_context;
	void			*win_id;
	void			*img_id;
	t_img			img;
};

/*
** Create a new mlx window
** Return false on error
*/
bool			ft_mlx_open(t_mlx_win *dst, void *mlx, t_vec2u size,
					t_sub title);

/*
** Put image to window
*/
void			ft_mlx_update(t_mlx_win *win);

/*
** Close window
*/
void			ft_mlx_close(t_mlx_win *win);

#endif
