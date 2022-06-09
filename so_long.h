/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:35:34 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:51:55 by jaeyjeon         ###   ########.fr       */
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
	void		*p;
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
	int			count_e;
	int			count_p;
	int			count_c;
}	t_param;

void	freemap(t_param *par);
void	set_param(t_param *par);
int		checkmap_length(t_param *par);
int		copyline(char *str, t_param *par);
int		copymap(t_param *par);
int		check_wall_end(char *str);
int		check_wall_middle(char *str);
int		check_wall(t_param *par, int linenum);
int		check_line_len(t_param *par);
int		check_map(t_param *par);
int		check_line(char *str);
int		check_map_char(t_param *par);
int		drawmap(t_param *par);
int		esc_press(int keycode);
int		redbut(void);
void	draw_img(char a, t_param *par, int x, int y);

#endif
