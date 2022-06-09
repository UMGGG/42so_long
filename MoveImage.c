/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveImage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:14:24 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/07 15:53:27 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W && param->y != 0)
	{
		param->y -= param->he;
		param->move++;
	}
	if (keycode == KEY_S && param->y != 480)
	{
		param->y += param->he;
		param->move++;
	}
	else if (keycode == KEY_A && param->x != 0)
	{
		param->x -= param->wi;
		param->move++;
	}
	else if (keycode == KEY_D && param->x != 480)
	{
		param->x += param->wi;
		param->move++;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	printf("move: %d\n", param->move);
	return (0);
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	drawmap(loc);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, loc->x, loc->y);
	return (0);
}

int	redbut(void)
{
	printf ("press red button");
	exit (0);
	return (0);
}
