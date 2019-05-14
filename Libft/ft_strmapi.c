/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:33:34 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/08 11:44:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fstr;
	int		i;
	int		j;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	fstr = (char*)malloc((j + 1) * sizeof(char));
	if (fstr != NULL)
	{
		while (s[i])
		{
			fstr[i] = f(i, s[i]);
			i++;
		}
	}
	else
		return (NULL);
	fstr[i] = '\0';
	return (fstr);
}
