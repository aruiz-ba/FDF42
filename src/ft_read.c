/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:19:30 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/04/30 14:11:07 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printmap(t_list *head)
{
	t_list *wolf;

	wolf = head;
	while (wolf != NULL)
	{
		ft_putstr(wolf->content);
		ft_putchar('\n');
		wolf = wolf->next;
	}
}
