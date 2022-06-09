/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:43:01 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:09:47 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_end(char *str)
{
	while (*str != '\n')
	{
		if (*str != '1')
		{
			printf("끝에 1아닌게 있음\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int	check_wall_middle(char *str)
{
	char	a;

	if (*str != '1')
	{
		printf("중간 시작이 1아님\n");
		return (0);
	}
	while (*str != '\n')
	{
		a = *str;
		str++;
	}
	if (a != '1')
	{
		printf("중간 끝이 1아님\n");
		return (0);
	}
	return (1);
}
