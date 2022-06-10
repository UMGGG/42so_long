/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:56:34 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/10 17:42:14 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_param(t_param *par)
{
	par->mlx = mlx_init();
	par->g = mlx_xpm_file_to_image(par->mlx, "imgs/g.xpm", &par->wi, &par->he);
	par->w = mlx_xpm_file_to_image(par->mlx, "imgs/r.xpm", &par->wi, &par->he);
	par->c = mlx_xpm_file_to_image(par->mlx, "imgs/c.xpm", &par->wi, &par->he);
	par->e = mlx_xpm_file_to_image(par->mlx, "imgs/e.xpm", &par->wi, &par->he);
	par->win = NULL;
	par->p = mlx_xpm_file_to_image(par->mlx, "imgs/p.xpm", &par->wi, &par->he);
	par->x = 0;
	par->y = 0;
	par->win_width = 0;
	par->win_height = 0;
	par->move = 0;
	par->fd = open("maps/map.ber", O_RDONLY);
	par->map = NULL;
	par->count_e = 0;
	par->count_p = 0;
	par->count_c = 0;
	par->p_x = 0;
	par->p_y = 0;
}
