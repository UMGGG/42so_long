/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:49:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/15 19:06:24 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_press(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
	{
		printf ("press ESC button");
		freemap(par);
		exit(0);
	}
	return (0);
}

int	redbut(t_param *par)
{
	printf ("press red button");
	freemap(par);
	exit (0);
	return (0);
}
