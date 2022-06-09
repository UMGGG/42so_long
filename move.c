/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:26:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 20:30:50 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_p(t_param *par)
{
	t_mapline	*curline;
	char		*str;
	int			countx;
	int			county;

	curline = par->map;
	countx = 0;
	county = 0;
	while (curline)
	{
		str = curline->line;
		while (*str != '\n')
		{
			if (*str == 'P')
			{
				par->p_x = countx;
				par->p_y = county;
				return ;
			}
			str++;
			countx++;
		}
		curline = curline->next;
		countx = 0;
		county++;
	}
}
