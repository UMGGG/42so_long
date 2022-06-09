/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:47:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 19:23:14 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(char a, t_param *par, int x, int y)
{
	if (a == '0')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
	else if (a == '1')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->w, x, y);
	else if (a == 'P' || a == 'C' || a == 'E')
	{
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
		if (a == 'P')
			mlx_put_image_to_window(\
			par->mlx, par->win, par->p, x, y);
		else if (a == 'C')
			mlx_put_image_to_window(\
			par->mlx, par->win, par->c, x, y);
		else if (a == 'E')
			mlx_put_image_to_window(\
			par->mlx, par->win, par->e, x, y);
	}
}

int	drawmap(t_param *par)
{
	t_mapline	*currline;
	char		*str;
	int			x;
	int			y;

	x = 0;
	y = 0;
	mlx_clear_window(par->mlx, par->win);
	currline = par->map;
	while (currline)
	{
		str = currline->line;
		while (*str != '\n')
		{
			draw_img(*str, par, x, y);
			str++;
			x += par->wi;
		}
		currline = currline->next;
		x = 0;
		y += par->he;
	}
	return (0);
}
