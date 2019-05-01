/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:56:32 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/04/30 11:35:34 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*reverse(t_list *head)
{
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

int		ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

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

t_list	*ft_parse_file(char *root, int *ln, int *dt)
{
	t_parse	prs;
	t_list	*split;
	t_list	*head;
	t_list	*node;
	t_list	*wolf;

	head = NULL;
	*ln = 0;
	prs.fd = open(root, O_RDONLY);
	while ((get_next_line(prs.fd, &prs.buff)) != 0)
	{
		prs.wrds = ft_strlen(prs.buff);
		node = ft_lstnew(prs.buff, prs.wrds + 1);
		node->content_size = ft_wordcount(prs.buff, ' ');
		if (head)
			ft_lstadd(&head, node);
		else
			node->next = NULL;
		head = node;
		*ln += 1;
	}
	*dt = node->content_size;
	head = reverse(head);
	return (head);
}
