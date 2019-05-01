/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:30:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/08 11:45:11 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		a;
	char	*out;

	i = 0;
	a = 0;
	while (s1[i])
		i++;
	out = (char*)malloc(i * sizeof(char) + 1);
	if (out == NULL)
		return (NULL);
	while (a < i)
	{
		out[a] = s1[a];
		a++;
	}
	out[a] = '\0';
	return (out);
}
