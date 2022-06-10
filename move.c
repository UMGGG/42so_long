/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:26:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/10 16:53:37 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_p(t_param *par)
{
	t_mapline	*curline;
	char		*str;

	curline = par->map;
	par->p_x = 0;
	par->p_y = 0;
	while (curline)
	{
		str = curline->line;
		while (*str != '\n')
		{
			if (*str == 'P')
				return ;
			str++;
			par->p_x++;
		}
		curline = curline->next;
		par->p_x = 0;
		par->p_y++;
	}
}

int	get_e(t_param *par)
{
	if (par->count_c == 0)
	{
		freemap(par);
		exit(0);
		return (0);
	}
	else
		return (1);
}
