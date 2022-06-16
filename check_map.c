/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:20:26 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/17 02:31:02 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_param *par)
{
	int	map_line;

	map_line = check_line_len(par);
	par->win_height = map_line * par->he;
	par->win_width = (ft_strlen(par->map->line) - 1) * par->wi;
	if (map_line)
		if (check_wall(par, map_line))
			if (check_map_char(par))
				return (1);
	return (0);
}

int	check_line_len(t_param *par)
{
	t_mapline	*curline;
	int			before_line_len;
	int			curr_line_len;
	int			line_count;

	before_line_len = 0;
	line_count = 0;
	curline = par->map;
	before_line_len = ft_strlen(curline->line);
	while (curline)
	{
		line_count++;
		curr_line_len = ft_strlen(curline->line);
		if (before_line_len != curr_line_len)
			return (print_err("줄 길이가 다름"));
		before_line_len = curr_line_len;
		curline = curline->next;
	}
	if (line_count >= 3)
		return (line_count);
	return (print_err("줄이 3줄 이하임"));
}

int	check_wall(t_param *par, int linenum)
{
	int			line_count;
	int			end_line;
	t_mapline	*curline;

	line_count = 0;
	end_line = linenum;
	curline = par->map;
	while (curline)
	{
		if (line_count == 0 || line_count == end_line - 1)
		{
			if (!check_wall_end(curline->line))
				return (print_err("벽이 다 둘러져있지않습니다"));
		}
		else
		{
			if (!check_wall_middle(curline->line))
				return (print_err("벽이 다 둘러져있지않습니다"));
		}
		line_count++;
		curline = curline->next;
	}
	return (1);
}

int	check_map_char(t_param *par)
{
	t_mapline	*curline;
	char		*str;

	curline = par->map;
	while (curline)
	{
		str = curline->line;
		while (*str != '\n')
		{
			if (*str == 'E')
				par->count_e++;
			else if (*str == 'P')
				par->count_p++;
			else if (*str == 'C')
				par->count_c++;
			else if (*str != '1' && *str != '0')
				return (0);
			str++;
		}
		curline = curline->next;
	}
	if (par->count_e != 1 || par->count_p != 1 || par->count_c < 1)
		return (print_err("탈출구, 시작지점, 수집품의 시작조건이 맞지않습니다"));
	return (1);
}

int	print_err(char *str)
{
	printf("%s\n", str);
	return (0);
}
