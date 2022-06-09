/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:17:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:53:29 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_param		par;
	int			mapstat;

	set_param(&par);
	copymap(&par);
	mapstat = check_map(&par);
	if (mapstat == 0)
	{
		printf("ERROR!\n");
		return (0);
	}
	drawmap(&par);
	mlx_key_hook(par.win, &esc_press, &par);
	mlx_hook(par.win, PRESS_RED_BUTTON, 0, &redbut, &par);
	mlx_loop(par.mlx);
	return (0);
}
