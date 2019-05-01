/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/01 19:12:35 by aruiz-ba         ###   ########.fr       */
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
}

void	deal_key2(int key, t_mlx *mlx)
{
	if (key == ZOOMIN)
	{
		mlx->map->size += 10;
		mlx->map->mvz++;
		setall(mlx, iso);
	}
	if (key == ZOOMOUT)
	{
		mlx->map->size -= 10;
		mlx->map->mvz--;
		setall(mlx, iso);
	}
	if (key == Z)
	{
		mlx->map->mvz++;
		setall(mlx, iso);
	}
	if (key == X)
	{
		mlx->map->mvz--;
		setall(mlx, iso);
	}
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == ESC)
		exit(0);
	if (key == UP)
	{
		mlx->map->mvy -= 10;
		setall(mlx, iso);
	}
	if (key == DOWN)
	{
		mlx->map->mvy += 10;
		setall(mlx, iso);
	}
	if (key == RIGHT)
	{
		mlx->map->mvx += 10;
		setall(mlx, iso);
	}
	if (key == LEFT)
	{
		mlx->map->mvx -= 10;
		setall(mlx, iso);
	}
	if (key == M)
	{
		setall(mlx, paral);
	}
	deal_key2(key, mlx);
	ft_putnbr(key);
	return (1);
}

int		main(int argc, char **argv)
{
	t_main	main;
	t_mlx	mlx;
	t_map	map;
	t_list	*mp;
	t_image	*img;

	if (argc != 2)
		return (-1);
	main.i = 0;
	main.prb = -1;
	mlx.mlx = mlx_init();
	mp = ft_parse_file(argv[1], &main.ln, &main.dt);
	map = *ft_setsize(&map, main.ln, main.dt);
	main.x = ((setdensity(mp->content_size) * mp->content_size * 2) + 300);
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "UAU");
	img = new_image(&mlx);
	map = *setweb(mp, &map, iso);
	mlx.image = img;
	mlx.map = &map;
	mlx.mp = mp;
	fill_image(&img->ptr, &map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
