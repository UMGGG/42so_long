/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:29:31 by jaeyjeon         ###   ########.fr       */
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
	else if (a == 'P')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->c, x, y);
	else if (a == 'C')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
	else if (a == 'E')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
}

int	drawmap(t_param *par)
{
	t_mapline	*currline;
	char		*str;
	int			x;
	int			y;

	x = 0;
	y = 0;
	currline = par->map;
	str = currline->line;
	while (currline != NULL)
	{
		while (*str != '\0')
		{
			draw_img(*str, par, x, y);
			str++;
			x += par->wi;
		}
		currline = currline->next;
		str = currline->line;
		x = 0;
		y += par->he;
	}
	return (0);
}
