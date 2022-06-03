/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:42:08 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/03 15:59:42 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copymap(t_param *par)
{
	char	*str;

	str = get_next_line(par->fd);
	while (str != NULL)
	{
		printf("----%s", str);
		if (copyline(str, par->map) == 0)
		{
			freeall(par);
			return (0);
		}
		str = get_next_line(par->fd);
	}
	free (str);
	return (1);
}

int	copyline(char *str, t_mapline *start)
{
	t_mapline	*line;
	t_mapline	*currline;

	currline = start;
	if (start == NULL)
	{
		line = malloc(sizeof(t_mapline));
		if (!line)
			return (0);
		line->next = NULL;
		line->line = ft_strdup(str);
		start = line;
	}
	else
	{
		while (currline->next != NULL)
			currline = currline->next;
		line = malloc(sizeof(t_mapline));
		if (line == NULL)
			return (0);
		line->next = NULL;
		line->line = ft_strdup(str);
		currline->next = line;
	}
	return (1);
}

void	freeall(t_param *par)
{
	t_mapline	*currline;
	t_mapline	*nextline;

	currline = par->map;
	while (currline != NULL)
	{
		nextline = currline->next;
		free (currline);
		currline = nextline;
	}
	free (currline);
}

int	main(void)
{
	t_param		par;
	t_mapline	*currline;
	char		*str;

	set_param(&par);
	str = get_next_line(par.fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(par.fd);
	}
	par.fd = open("maps/map.ber", O_RDONLY);
	printf("--------------------------------\n");
	copymap(&par);
	currline = par.map;
	printf("%s", currline->line);
	while (currline != NULL)
	{
		printf("%s", currline->line);
		currline = currline->next;
	}
}
