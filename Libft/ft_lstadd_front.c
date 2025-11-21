/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:41:10 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 13:41:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int	main()
{
	t_list *head = NULL;
	t_list *curr = NULL;
	char *data[] = {"one", "two", "three", "four"};

	head = ft_lstnew(data[0]);
	curr = head;
	for (int i = 1; i < 4; i++)
	{
		curr->next = ft_lstnew(data[i]);
		curr = curr->next;
	}
	ft_lstadd_front(&head, ft_lstnew("zero"));
	curr = head;
	while (curr)
	{
		printf("content : %s\n", (char *)curr->content);
		curr = curr->next;
	}
	curr = head;
	while (curr)
	{
		t_list *tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return (0);
}*/