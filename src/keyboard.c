/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:09:49 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/27 14:45:51 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setall(t_mlx *mlx, t_screen (*f)(t_map *map))
{
	freeimage(&mlx->image->ptr);
	freegrid(mlx->map);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->map = setweb(mlx->mp, mlx->map, f);
	fill_image(&mlx->image->ptr, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	put_text(mlx);
}

void	zoom(int key, t_mlx *mlx)
{
	if (key == ZOOMIN)
	{
		mlx->map->size += 1;
		mlx->map->mvz++;
		setall(mlx, mlx->f);
	}
	if (key == ZOOMOUT)
	{
		if (mlx->map->size > 0)
		{
			mlx->map->size -= 1;
			mlx->map->mvz--;
		}
		setall(mlx, mlx->f);
	}
}

int		deal_key(int key, t_mlx *mlx)
{
	zoom(key, mlx);
	if (key == Z)
		mlx->map->mvz++;
	if (key == X)
		mlx->map->mvz--;
	if (key == M)
		mlx->f = paral;
	if (key == N)
		mlx->f = iso;
	if (key == ESC)
		exit(0);
	if (key == UP)
		mlx->map->mvy -= 10;
	if (key == DOWN)
		mlx->map->mvy += 10;
	if (key == RIGHT)
		mlx->map->mvx += 10;
	if (key == LEFT)
		mlx->map->mvx -= 10;
	if (key == Z || key == X || key == M || key == N || key == UP
		|| key == DOWN || key == RIGHT || key == LEFT)
		setall(mlx, mlx->f);
	return (1);
}
