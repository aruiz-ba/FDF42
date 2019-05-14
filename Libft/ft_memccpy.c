/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:51:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/08 11:43:46 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*des;
	char const		*sr;

	des = dest;
	sr = src;
	while (n--)
	{
		*des++ = *sr;
		if ((unsigned char)*sr == (unsigned char)c)
			return (des);
		sr++;
	}
	return (NULL);
}
