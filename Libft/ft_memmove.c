/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:09:54 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 09:59:42 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if (dst < src)
		while (++i < len)
			((char*)dst)[i] = ((char*)src)[i];
	if (dst > src)
	{
		while ((int)(--len) >= 0)
			((char*)dst)[len] = ((char*)src)[len];
	}
	return (dst);
}
