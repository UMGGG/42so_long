/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:43:01 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/10 18:03:19 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_end(char *str)
{
	while (*str != '\n')
	{
		if (*str != '1')
			return (print_err("끝에 1아닌게 있음"));
		str++;
	}
	return (1);
}

int	check_wall_middle(char *str)
{
	char	a;

	if (*str != '1')
		return (print_err("중간 시작이 1 아님"));
	while (*str != '\n')
	{
		a = *str;
		str++;
	}
	if (a != '1')
		return (print_err("중간 끝이 1 아님"));
	return (1);
}
