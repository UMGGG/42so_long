/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:49:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:51:45 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_press(int keycode)
{
	if (keycode == KEY_ESC)
	{
		printf ("press ESC button");
		exit(0);
	}
	return (0);
}

int	redbut(void)
{
	printf ("press red button");
	exit (0);
	return (0);
}
