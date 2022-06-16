/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:17:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/16 18:10:03 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_param		par;
	int			mapstat;

	set_param(&par);
	if (par.fd <= 0)
	{
		printf("Error\nInvalidMapFile\n");
		return (0);
	}
	copymap(&par);
	mapstat = check_map(&par);
	if (mapstat == 0)
	{
		printf("Error\n");
		freemap(&par);
		return (0);
	}
	set_p(&par);
	par.win = mlx_new_window(par.mlx, par.win_width, par.win_height, "so_long");
	drawmap(&par);
	mlx_key_hook(par.win, &key_press, &par);
	mlx_hook(par.win, PRESS_RED_BUTTON, 0, &redbut, &par);
	mlx_loop(par.mlx);
	return (0);
}
