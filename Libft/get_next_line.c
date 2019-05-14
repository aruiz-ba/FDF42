/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:31:33 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 17:13:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	save(int fd, char **line, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strsub(str[fd], 0, i);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	static char	*str[FD_SIZE];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((nbread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (nbread < 0)
		return (-1);
	if (nbread == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (save(fd, line, str));
}
