/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:17:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 10:11:01 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srlen;
	size_t	dslen;

	dslen = ft_strlen(dst);
	srlen = ft_strlen(src);
	i = 0;
	if (size < dslen)
		return (size + srlen);
	while (src[i] != '\0' && (dslen + i + 1) < size)
	{
		dst[dslen + i] = src[i];
		i++;
	}
	dst[dslen + i] = '\0';
	return (srlen + dslen);
}
