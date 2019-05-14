/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:43:07 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/13 15:45:30 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		digitlen(char **str)
{
	int			len;

	len = -1;
	while (str[len] != NULL)
		++len;
	return (len);
}

int		ft_atoi_base(const char *str)
{
	int		len;
	int		i;
	int		decimal;
	char	digit;

	i = 0;
	decimal = 0;
	len = ft_strlen(str + 1);
	while (i <= len)
	{
		digit = ft_toupper(str[len - i]);
		if (digit >= '0' && digit <= '9')
			decimal += (digit - '0') * pow(16, i);
		else
			decimal += (digit - 'A' + 10) * pow(16, i);
		i++;
	}
	return (decimal);
}

int		checkifcolor(char *str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (i++ < len - 1)
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
				return (0);
			else
				return (-1);
		}
	}
	return (1);
}

char	*intrim(char const *s)
{
	int		i;
	int		a;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	a = -1;
	while (s[i] != '0' && s[i + 1] != 'x')
		i++;
	i -= 2;
	if (!(str = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	while (a++ < i)
		str[a] = *s++;
	str[a] = '\0';
	return (str);
}

int		setcolor(char *array, int *z)
{
	char *str;

	str = intrim(array);
	*z = ft_atoi(array);
	str = ft_strtrimstr(array, str);
	return (ft_atoi_base(str + 3));
}
