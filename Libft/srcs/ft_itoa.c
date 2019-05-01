/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:27:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 09:56:38 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	short	sign;
	long	l;

	sign = 0;
	l = n;
	len = ft_intlen(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (l < 0)
	{
		sign = 1;
		l *= -1;
	}
	while (len--)
	{
		res[len] = l % 10 + '0';
		l /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
