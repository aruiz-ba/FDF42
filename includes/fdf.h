/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:23:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/01 19:12:21 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include "../Libft/includes/libft.h"
#include <stdio.h>	//remember to remove me
#include <math.h>
# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define ESC		53
# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define ZOOMIN		69
# define ZOOMOUT	78
# define Z			6
# define X			7
# define M			46
typedef struct	s_screen
{
	int			x;
	int			y;
	int			z;
}				t_screen;

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
	int			tmz;
	int			size;
	int			mvx;
	int			mvy;
	int			mvz;
	int			color;
	unsigned int grid[WIN_WIDTH + 11][WIN_HEIGHT + 11];
}				t_map;

typedef struct	s_main
{
	int		x;
	int		y;
	int		prb;
	int		i;
	int		ln;
	int		dt;
}				t_main;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	*image;
	t_list	*mp;
	int		k;
}				t_mlx;

typedef struct	s_bresenham
{
	int	dy;
	int	dx;
	int	avr;
	int	av;
	int	avi;
	int	xy[2];
	int	inxi;
	int	inyi;
	int	inxr;
	int	inyr;
	int	tmp;
}				t_bresenham;

typedef struct	s_setweb
{
	int			i;
	int			s;
	int			c;
	char		**array;
}				t_setweb;

typedef struct	s_parse
{
	int		fd;
	int		wrds;
	char	*buff;
}				t_parse;

int			bresenham(t_screen screen1, t_screen screen2, t_map *map);
t_map		*setweb(t_list *mp, t_map *map, t_screen (*f)(t_map *map));
t_list		*ft_parse_file(char *root, int *ln, int *dt);
void		printmap(t_list *head);
t_list		*reverse(t_list	*head);
int			setdensity (size_t t);
void		fill_image(char **image_string, t_map *map);
t_image		*new_image(t_mlx *mlx);
void		freeimage(char **image_string);
void		freegrid(t_map *map);
t_map		*ft_center(t_map *map, int ln, int dt);
t_screen	xro(t_map *map);
t_map		*ft_setsize(t_map *map, int ln, int dt);
int			setcolor(char *array, int *z);
int			ft_atoi_base(const char *str);
int			checkifcolor(char *str);
void		stww(t_list *wolf, t_setweb *stw, t_map *map, t_screen (*f)(t_map *map));
void		stww2(t_list *wolf, t_setweb *stw, t_map *map, t_screen (*f)(t_map *map));
t_screen	iso(t_map *map);
char		*intrim(char const *s);
t_screen	paral(t_map *map);
#endif