/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:17:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/09 18:23:16 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_param		par;
	int			mapstat;

	set_param(&par);
	copymap(&par);
	mapstat = check_map(&par);
	if (mapstat == 1)
		printf("GOOD!\n");
	else
		printf("ERROR!\n");
	return (0);
}
