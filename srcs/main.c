/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/03 17:01:56 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_text(t_mlx	*mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 1000, 20, 0xFFFFF, "'AWSD' to move");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 40, 0xFFFFF, "'Z & X' for z value");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 60, 0xFFFFF, "'M' for parallel");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 80, 0xFFFFF, "'O & P' for zoom");
}

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

void	deal_key2(int key, t_mlx *mlx)
{
	if (key == ZOOMIN)
	{
		mlx->map->size += 1;
		mlx->map->mvz--;
		setall(mlx, mlx->f);
	}
	if (key == ZOOMOUT)
	{
		mlx->map->size -= 1;
		mlx->map->mvz++;
		setall(mlx, mlx->f);
	}
	if (key == Z)
	{
		mlx->map->mvz++;
		setall(mlx, mlx->f);
	}
	if (key == X)
	{
		mlx->map->mvz--;
		setall(mlx, mlx->f);
	}
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == M)
	{
		mlx->f = paral;
		setall(mlx, mlx->f);
	}
	if (key == ESC)
		exit(0);
	if (key == UP)
	{
		mlx->map->mvy -= 10;
		setall(mlx, mlx->f);
	}
	if (key == DOWN)
	{
		mlx->map->mvy += 10;
		setall(mlx, mlx->f);
	}
	if (key == RIGHT)
	{
		mlx->map->mvx += 10;
		setall(mlx, mlx->f);
	}
	if (key == LEFT)
	{
		mlx->map->mvx -= 10;
		setall(mlx, mlx->f);
	}
	if (key == N)
	{
		mlx->f = iso;
		setall(mlx, mlx->f);
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
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	img = new_image(&mlx);
	mlx.f = iso;
	map = *setweb(mp, &map, mlx.f);
	mlx.image = img;
	mlx.map = &map;
	mlx.mp = mp;
	fill_image(&img->ptr, &map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	put_text(&mlx);
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
