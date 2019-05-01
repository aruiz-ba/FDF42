/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:15:33 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/04/30 17:30:09 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeimage(char **image_string)
{
	int		i;
	int		j;
	int		k;
	int		color;

	color = 0xFFFFFF;
	k = 0;
	i = 0;
	while (i < (WIN_HEIGHT * WIN_WIDTH))
	{
		(*image_string)[k + 0] = (char)(color % 256 % 256);
		(*image_string)[k + 1] = (char)(color / 256 % 256);
		(*image_string)[k + 2] = (char)(color / 256 / 256);
		(*image_string)[k + 3] = 0;
		k += 4;
		i++;
	}
}

void	freegrid(t_map *map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			map->grid[j][i] = 0x00000;
			j++;
		}
		i++;
	}
}

void	fill_image(char **image_string, t_map *map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			(*image_string)[k + 0] = (char)(map->grid[j][i] % 256 % 256);
			(*image_string)[k + 1] = (char)(map->grid[j][i] / 256 % 256);
			(*image_string)[k + 2] = (char)(map->grid[j][i] / 256 / 256);
			(*image_string)[k + 3] = 0;
			k += 4;
			j++;
		}
		i++;
	}
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*m;

	if ((m = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	m->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->ptr = mlx_get_data_addr(m->image, &m->bpp, &m->stride, &m->endian);
	return (m);
}
