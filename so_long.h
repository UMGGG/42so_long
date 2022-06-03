/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:35:34 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/03 15:37:18 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "inc/42Get_Next_Line/get_next_line.h"

# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17

typedef struct s_mapline
{
	char				*line;
	struct s_mapline	*next;
}	t_mapline;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	void		*c;
	void		*g;
	void		*w;
	t_mapline	*map;
	size_t		fd;
	int			x;
	int			y;
	int			wi;
	int			he;
	int			win_width;
	int			win_height;
	int			move;
}	t_param;

void	draw_img(char a, t_param *par, int x, int y);
void	freeall(t_param *par);
void	set_param(t_param *par);
int		drawmap(t_param *par);
int		checkmap_length(t_param *par);
int		copyline(char *str, t_mapline *start);
int		copymap(t_param *par);

#endif
