/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 14:12:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	if (!lst)
		return (0);
	current = lst;
	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main()
{
	t_list	*head = NULL;
	t_list	*curr = NULL;
	char	*data[] = {"1", "2", "3", "4"};
	int		i = 0;

	for (; i < 4; i++)
		ft_lstadd_front(&head, ft_lstnew(data[i]));
	curr = head;
	while (curr)
	{
		printf("content : %s\n", (char *)curr->content);
		curr = curr->next;
	}
	curr = head;
	printf("len : %d\n", ft_lstsize(head));
	while (curr)
	{
		t_list	*tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return (0);
}*/