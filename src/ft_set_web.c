/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_web.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:57:03 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/10 15:31:35 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			setdensity(size_t t)
{
	int	i;

	if (t < 10)
		i = 30;
	if (t > 10 && t < 20)
		i = 20;
	if (t > 20)
		i = 4;
	return (i);
}

t_screen	iso(t_map *map)
{
	int			previous_x;
	int			previous_y;
	t_screen	screen;

	previous_x = map->x;
	previous_y = map->y;
	screen.x = ((previous_x - previous_y) * cos(0.523599) * map->size
	+ map->mvx);
	screen.y = ((previous_x + previous_y) * sin(0.523599) * map->size
	+ map->mvy) - (map->z * map->mvz);
	return (screen);
}

t_screen	paral(t_map *map)
{
	int			previous_x;
	int			previous_y;
	t_screen	screen;

	previous_x = map->x;
	previous_y = map->y;
	screen.x = ((previous_x - previous_y) * map->size
	+ map->mvx);
	screen.y = ((previous_x + previous_y) * map->size
	+ map->mvy) - (map->z * map->mvz);
	return (screen);
}

int			setweb2(t_list *mp, t_map *map, t_screen (*f)(t_map *map))
{
	t_setweb	stw;
	t_list		*wolf;

	stw.i = -1;
	wolf = mp;
	map->x = -1;
	map->y = 0;
	stw.c = mp->content_size - 1;
	stw.s = setdensity(stw.c);
	while (map->x++ < stw.c)
	{
		wolf = mp;
		if (stww2(wolf, &stw, map, f) == -1)
			return (-1);
		map->y = 0;
	}
	return (0);
}

t_map		*setweb(t_list *mp, t_map *map, t_screen (*f)(t_map *map))
{
	t_setweb	stw;
	t_list		*wolf;

	stw.i = -1;
	wolf = mp;
	map->x = -1;
	map->y = 0;
	wolf = mp;
	stw.s = setdensity(mp->content_size);
	if (stww(wolf, &stw, map, f) == -1)
		return (NULL);
	if (setweb2(mp, map, f) == -1)
		return (NULL);
	return (map);
}
