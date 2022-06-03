/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/03 15:10:08 by jaeyjeon         ###   ########.fr       */
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

int	checkmap_length(t_param *par)
{
	char	*str;
	int		check_p;

	check_p = 0;
	str = get_next_line(par->fd);
	if (str == NULL)
	{
		printf("널값 받아짐");
		return (0);
	}
	par->win_width = ft_strlen(str);
	while (str != NULL && *str != '\n')
	{
		par->win_height++;
		if (ft_strlen(str) != (size_t)par->win_width)
		{
			printf("길이 다름");
			return (0);
		}
		while (*str != '\0')
		{
			if (*str == 'P')
				check_p++;
			str++;
		}
		str = get_next_line(par->fd);
	}
	return (1);
}

int	drawmap(t_param *par)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	par->fd = open("maps/map.ber", O_RDONLY);
	str = get_next_line(par->fd);
	while (str != NULL)
	{
		while (*str != '\0')
		{
			draw_img(*str, par, x, y);
			str++;
			x += par->wi;
		}
		str = get_next_line(par->fd);
		x = 0;
		y += par->he;
	}
	return (0);
}
