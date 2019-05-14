/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:15:49 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/05 19:06:57 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;

	a = 0;
	i = 0;
	if ((needle[0] == '\0') || (haystack[0] == '\0' && needle[0] == '\0'))
		return ((char*)(haystack));
	while (i < len && haystack[i])
	{
		while (haystack[i + a] == needle[a] && ((i + a) < len))
		{
			if (!needle[a + 1])
				return ((char*)(haystack + i));
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}
