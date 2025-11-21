/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:47:05 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 14:47:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	ft_del(void *content)
{
	free(content);
}
#include <stdio.h>
int	main()
{
	t_list	*head = NULL;
	t_list	*to_del = NULL;
	t_list	*curr = NULL;

	ft_lstadd_back(&head, ft_lstnew(ft_strdup("one")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("three")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("four")));
	to_del = head->next;
	head->next = to_del->next;
	ft_lstdelone(to_del, ft_del);
	curr = head;
	for(; curr; curr = curr->next)
		printf("content : %s\n", (char *)curr->content);
	curr = head;
	while (curr)
	{
		t_list	*tmp = curr;
		curr = curr->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}*/