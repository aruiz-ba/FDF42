/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:43:07 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/01 18:33:39 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//THIS IS TO READ THE COLOR FROM A MAP

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
		digit = str[len - i];
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
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

char		*intrim(char const *s)
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
int			setcolor(char *array, int *z)
{
	char *str;

	str = intrim(array);
	*z = atoi(array);
	str = ft_strtrimstr(array, str);
	return (ft_atoi_base(str + 3));
}
