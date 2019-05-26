/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_stwebwhile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:56:10 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/26 18:07:32 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		sub_stww2(t_setweb *stw, t_map *map)
{
	int	i;

	if ((i = checkifcolor(stw->array[map->x])) == 0)
		map->color = setcolor(stw->array[map->x], &map->z);
	else if (i == -1)
		return (-1);
	else
	{
		map->z = ft_atoi(stw->array[map->x]);
		map->color = 0xa3ff03;
	}
	return (0);
}

int		sub_stww(t_map *map, t_setweb *stw, t_sn *sn, t_screen (*f)(t_map *map))
{
	t_screen	screen1;
	t_screen	screen2;

	screen1.x = -1;
	screen1.y = -1;
	while (map->x++ < (stw->i - 1))
	{
		sn->screen1 = &screen1;
		sn->screen2 = &screen2;
		if (ifstw(stw, map, sn, f) == -1)
			return (-1);
		map->tmz = map->z;
	}
	return (0);
}
