/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:30:37 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 14:30:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
/*
#include <stdio.h>
int	main()
{
	t_list	*head = NULL;
	t_list	*curr = NULL;
	char	*data[] = {"1", "2", "3", "4"};

	for (int i = 0; i < 4; i++)
		ft_lstadd_back(&head, ft_lstnew(data[i]));
	curr = head;
	while (curr)
	{
		printf("content : %s\n", (char *)curr->content);
		curr = curr->next;
	}
	while (curr)
	{
		t_list	*tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return (0);
}*/