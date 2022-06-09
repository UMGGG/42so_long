/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:18:26 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 20:58:42 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_param *par)
{
	if (keycode == KEY_W)
	{
		if (par->p_y != 1)
			move_up(par);
	}
	else if (keycode == KEY_S && par->y != 480)
	{
		par->move++;
	}
	else if (keycode == KEY_A)
	{
		printf("%d\n", par->p_x);
		move_left(par);
	}
	else if (keycode == KEY_D)
	{
		printf("%d\n", par->p_x);
		if (par->p_x != (int)(ft_strlen(par->map->line) - 3))
			move_right(par);
	}
	else if (keycode == KEY_ESC)
		esc_press(keycode);
	printf("move: %d\n", par->move);
	drawmap(par);
	return (0);
}

void	move_left(t_param *par)
{
	t_mapline	*curline;
	char		*str;
	int			x;
	int			y;

	curline = par->map;
	x = par->p_x;
	y = par->p_y;
	str = curline->line;
	while (y != 0)
	{
		curline = curline->next;
		str = curline->line;
		y--;
	}
	while (x != 0)
	{
		if (x == 1)
		{
			if (*str == '1')
				return ;
			else
			{
				if (*str == 'C')
					par->count_c--;
				*str = 'P';
			}
		}
		str++;
		x--;
	}
	*str = '0';
	par->move++;
	set_p(par);
}

void	move_right(t_param *par)
{
	t_mapline	*curline;
	char		*str;
	int			x;
	int			y;

	curline = par->map;
	x = par->p_x;
	y = par->p_y;
	str = curline->line;
	while (y != 0)
	{
		curline = curline->next;
		str = curline->line;
		y--;
	}
	while (x != 0)
	{
		str++;
		x--;
	}
	*str = '0';
	str++;
	*str = 'P';
	par->move++;
	set_p(par);
}

void	move_up(t_param *par)
{
	t_mapline	*curline;
	char		*str;
	int			x;
	int			y;

	curline = par->map;
	x = par->p_x;
	y = par->p_y;
	str = curline->line;
	while (y != 0)
	{
		while (x != 0)
		{
			str++;
			x--;
		}
		if (y == 1)
			*str = 'P';
		x = par->p_x;
		curline = curline->next;
		str = curline->line;
		y--;
	}
	while (x != 0)
	{
		str++;
		x--;
	}
	*str = '0';
	par->move++;
	set_p(par);
}
