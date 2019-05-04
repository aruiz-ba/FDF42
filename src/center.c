/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:26:44 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/04/30 17:41:56 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_center(t_map *map, int ln, int dt)
{
	int	cx;
	int	cy;

	cx = WIN_WIDTH / 2;
	cy = WIN_HEIGHT / 2;
	ln = ln * map->size;
	dt = dt * map->size;
	ln = ln / 2;
	dt = dt / 2;
	map->mvy = cy - ln;
	map->mvx = cx - dt;
	freegrid(map);
	return (map);
}

t_map	*ft_setsize(t_map *map, int ln, int dt)
{
	if (dt <= 10)
	{
		map->size = 40;
		map->mvz = 20;
	}
	if (dt > 10 && dt < 30)
	{
		map->size = 30;
		map->mvz = 10;
	}
	if (ln > 30 && ln <= 250)
	{
		map->size = 5;
		map->mvz = 10;
	}
	if (ln > 250)
	{
		map->size = 1;
		map->mvz = 2;
	}
	return (ft_center(map, ln, dt));
}
