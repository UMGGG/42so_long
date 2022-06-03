/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:20:26 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/03 13:42:17 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(t_param par)
{

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
