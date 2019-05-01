/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stwebwhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:27:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/01 19:01:00 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	endloop(t_screen *screen1, t_screen *screen2, t_map *map)
{
	screen1->x = -1;
	screen1->y = -1;
	map->x = -1;
	map->y++;
}

void	stww(t_list *wolf, t_setweb *stw, t_map *map, t_screen (*f)(t_map *map))
{
	t_screen	screen1;
	t_screen	screen2;

	screen1.x = -1;
	screen1.y = -1;
	while (wolf != NULL)
	{
		stw->i = wolf->content_size;
		stw->array = ft_strsplit(wolf->content, ' ');
		while (map->x++ < (stw->i - 1))
		{
			if(checkifcolor(stw->array[map->x]) == 0)
			{
				map->color = setcolor(stw->array[map->x], &map->z);
				map->z = map->z * map->mvz;
			}
			else
			{
				map->color = 0xa3ff03;
				map->z = ft_atoi(stw->array[map->x]) * map->mvz;
			}
			if (screen1.x != -1 && screen1.y != -1)
			{
				screen2 = f(map);
				bresenham(screen1, screen2, map);
			}
			screen1 = f(map);
			map->tmz = map->z;
		}
		endloop(&screen1, &screen2, map);
		wolf = wolf->next;
	}
}

void	stww2(t_list *wolf, t_setweb *stw, t_map *map, t_screen (*f)(t_map *map))
{
	t_screen	screen1;
	t_screen	screen2;

	screen1.x = -1;
	screen1.y = -1;
	while (wolf != NULL)
	{
		stw->array = ft_strsplit(wolf->content, ' ');
		if(checkifcolor(stw->array[map->x]) == 0)
		{
				map->color = setcolor(stw->array[map->x], &map->z);
				map->z = map->z * map->mvz;
		}
		else
		{
			map->z = ft_atoi(stw->array[map->x]) * map->mvz;
			map->color = 0xa3ff03;
		}
		if (screen1.x != -1 && screen1.y != -1)
		{
			screen2 = f(map);
			bresenham(screen2, screen1, map);
		}
		screen1 = f(map);
		map->y++;
		wolf = wolf->next;
	}
	screen1.x = -1;
	screen1.x = -1;
	map->y = 0;
}
