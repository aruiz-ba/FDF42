/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:32:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/03 12:59:16 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	*ft_wordlen(char const *s, char c, int len)
{
	int *count;
	int i;

	if (!(count = malloc(sizeof(int) * len)))
		return (0);
	while (--len >= 0)
		count[len] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
			count[i]++;
		if ((*s != c && *(s + 1) == c) || (*s != c && !*(s + 1)))
			i++;
		s++;
	}
	return (count);
}

static void	ft_free2d(char **array, int len)
{
	int i;

	i = -1;
	while (++i < len)
		free(array[i]);
	free(array);
}

static void	ft_initialise(char **result, char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (*s)
	{
		if (*s != c)
			result[k][i++] = *s;
		if ((*s != c && *(s + 1) == c) || (*s != c && !*(s + 1)))
		{
			result[k++][i] = '\0';
			i = 0;
		}
		s++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	int		wordc;
	int		*count;
	int		i;
	char	**result;

	i = -1;
	if (!s)
		return (NULL);
	wordc = ft_wordcount(s, c);
	count = ft_wordlen(s, c, wordc);
	if (!(result = malloc(sizeof(char*) * (wordc + 1))))
		return (NULL);
	result[wordc] = NULL;
	while (++i < wordc)
		if (!(result[i] = malloc(sizeof(char) * (count[i] + 1))))
		{
			ft_free2d(result, wordc);
			return (NULL);
		}
	ft_initialise(result, s, c);
	free(count);
	return (result);
}
