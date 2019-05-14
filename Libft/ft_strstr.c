/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:33:17 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 10:15:14 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	a = 0;
	i = 0;
	if ((needle[0] == '\0') || (haystack[0] == '\0' && needle[0] == '\0'))
		return ((char*)(haystack));
	while (haystack[i])
	{
		while (haystack[i + a] == needle[a])
		{
			if (needle[a + 1] == '\0')
				return ((char*)(haystack + i));
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}
