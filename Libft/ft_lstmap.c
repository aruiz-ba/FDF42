/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:42:51 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/01/07 09:57:07 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(t_list *lst)
{
	t_list *temp;

	while (lst)
	{
		temp = lst;
		free(lst);
		lst = temp->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *begin;

	if (!lst || !f)
		return (NULL);
	if (!(result = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	result = f(result);
	lst = lst->next;
	begin = result;
	while (lst)
	{
		if (!(result->next = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_freeall(begin);
			return (NULL);
		}
		result->next = f(result->next);
		result = result->next;
		lst = lst->next;
	}
	return (begin);
}
