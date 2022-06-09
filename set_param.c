/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:56:34 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:44:18 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_param(t_param *par)
{
	par->mlx = mlx_init();
	par->g = mlx_xpm_file_to_image(par->mlx, "imgs/g.xpm", &par->wi, &par->he);
	par->w = mlx_xpm_file_to_image(par->mlx, "imgs/r.xpm", &par->wi, &par->he);
	par->win = mlx_new_window(par->mlx, 1000, 1000, "DrawMap");
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
}
