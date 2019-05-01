/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:38:16 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 10:06:28 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t a;

	a = 0;
	while (a < ft_strlen(src))
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (dst);
}
