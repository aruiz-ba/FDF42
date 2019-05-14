/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/10 15:39:49 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(void)
{
	ft_putstr("File did not opened correctly\n");
	return (0);
}

void	put_text(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 1000, 20, 0xFFFFF, "'AWSD' to move");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 40,
	0xFFFFF, "'Z & X' for z value");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 60, 0xFFFFF, "'M' for parallel");
	mlx_string_put(mlx->mlx, mlx->win, 1000, 80, 0xFFFFF, "'O & P' for zoom");
}

int		setimage(t_mlx *mlx, t_map *map, t_list *mp)
{
	t_image	*img;

	img = new_image(mlx);
	mlx->f = iso;
	if ((map = setweb(mp, map, mlx->f)) == NULL)
		return (-1);
	mlx->image = img;
	mlx->map = map;
	mlx->mp = mp;
	fill_image(&img->ptr, map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->image, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_main	main;
	t_mlx	mlx;
	t_map	map;
	t_list	*mp;

	if (argc != 2)
		return (-1);
	main.i = 0;
	main.prb = -1;
	mlx.mlx = mlx_init();
	if ((mp = ft_parse_file(argv[1], &main.ln, &main.dt)) == NULL)
		return (error());
	map = *ft_setsize(&map, main.ln, main.dt);
	main.x = ((setdensity(mp->content_size) * mp->content_size * 2) + 300);
	map.z = map.size;
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (setimage(&mlx, &map, mp) == -1)
		return (error());
	put_text(&mlx);
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
