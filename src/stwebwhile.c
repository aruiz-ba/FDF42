/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stwebwhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:27:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/14 17:09:34 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	endloop(t_screen *screen1, t_map *map, t_setweb *stw)
{
	int	i;

	i = -1;
	screen1->x = -1;
	screen1->y = -1;
	map->x = -1;
	map->y++;
	while (stw->array[++i] != NULL)
		free(stw->array[i]);
}

int		ifstw(t_setweb *stw, t_map *map, t_sn *sn, t_screen (*f)(t_map *map))
{
	int	i;

	if ((i = checkifcolor(stw->array[map->x])) == 0)
		map->color = setcolor(stw->array[map->x], &map->z);
	else if (i == -1)
		return (-1);
	else
	{
		map->color = 0xa3ff03;
		map->z = ft_atoi(stw->array[map->x]);
	}
	if (sn->screen1->x != -1 && sn->screen1->y != -1)
	{
		*sn->screen2 = f(map);
		bresenham(sn->screen1, sn->screen2, map);
	}
	*sn->screen1 = f(map);
	return (0);
}

int		sub_stww()
{
	
	return (0);
}

int		stww(t_list *wolf, t_setweb *stw, t_map *map, t_screen (*f)(t_map *map))
{
	t_screen	screen1;
	t_screen	screen2;
	t_sn		sn;
	int			i;
	int			len;

	screen1.x = -1;
	screen1.y = -1;
	len = -1;
	while (wolf != NULL)
	{
		i = -1;
		stw->i = wolf->content_size;
		stw->array = ft_strsplit(wolf->content, ' ');
		if (len == -1)
			len = digitlen(stw->array);
		else if (len != digitlen(stw->array) && len != -1)
			return (-1);
		while (map->x++ < (stw->i - 1))
		{
			sn.screen1 = &screen1;
			sn.screen2 = &screen2;
			if (ifstw(stw, map, &sn, f) == -1)
				return (-1);
			map->tmz = map->z;
		}
		endloop(&screen1, map, stw);
		wolf = wolf->next;
		free(stw->array);
	}
	return (0);
}

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

int		stww2(t_list *wolf, t_setweb *stw, t_map *map,
t_screen (*f)(t_map *map))
{
	t_screen	screen1;
	t_screen	screen2;
	int			i;

	screen1.x = -1;
	screen1.y = -1;
	while (wolf != NULL)
	{
		i = -1;
		stw->array = ft_strsplit(wolf->content, ' ');
		if (sub_stww2(stw, map) == -1)
			return (-1);
		if (screen1.x != -1 && screen1.y != -1)
		{
			screen2 = f(map);
			bresenham(&screen2, &screen1, map);
		}
		screen1 = f(map);
		map->y++;
		wolf = wolf->next;
		while (stw->array[++i] != NULL)
			free(stw->array[i]);
		free(stw->array);
	}
	return (0);
}
