/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:37:06 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/01 18:44:35 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ifels(t_bresenham *br, t_screen *screen1, t_screen *screen2, t_map *map)
{
	if (br->dx >= 0)
		br->inxi = 1;
	else
	{
		br->dx = -br->dx;
		br->inyi = -1;
	}
	if (br->dx >= br->dy)
	{
		br->inyr = 0;
		br->inxr = br->inxi;
	}
	else
	{
		br->inxr = 0;
		br->inyr = br->inyi;
		br->tmp = br->dx;
		br->dx = br->dy;
		br->dy = br->tmp;
	}
}

void	brs2(t_bresenham *br, t_screen *screen1, t_screen *screen2, t_map *map)
{
	br->xy[0] = screen1->x;
	br->xy[1] = screen1->y;
	br->avr = (2 * br->dy);
	br->av = (br->avr - br->dx);
	br->avi = (br->av - br->dx);
	while (br->xy[0] != screen2->x || br->xy[1] != screen2->y)
	{
		if ((br->xy[0] >= 0 && br->xy[0] <= WIN_WIDTH) &&
		(br->xy[1] >= 0 && br->xy[1] <= WIN_HEIGHT))
			map->grid[br->xy[0]][br->xy[1]] = map->color;
		if (br->av >= 0)
		{
			br->xy[0] = (br->xy[0] + br->inxi);
			br->xy[1] = (br->xy[1] + br->inyi);
			br->av = (br->av + br->avi);
		}
		else
		{
			br->xy[0] = (br->xy[0] + br->inxr);
			br->xy[1] = (br->xy[1] + br->inyr);
			br->av = (br->av + br->avr);
		}
	}
}

int		bresenham(t_screen screen1, t_screen screen2, t_map *map)
{
	t_bresenham br;

	br.dy = (screen2.y - screen1.y);
	br.dx = (screen2.x - screen1.x);
	if (br.dy >= 0)
		br.inyi = 1;
	else
	{
		br.dy = -br.dy;
		br.inyi = -1;
	}
	ifels(&br, &screen1, &screen2, map);
	brs2(&br, &screen1, &screen2, map);
	return (0);
}
