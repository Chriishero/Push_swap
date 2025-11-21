/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:26:13 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 14:26:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
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
	printf("last : %s\n", (char *)ft_lstlast(head)->content);
	while (curr)
	{
		t_list	*tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return (0);
}*/