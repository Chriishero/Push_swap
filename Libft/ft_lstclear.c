/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:01:41 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 15:01:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dummy;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		dummy = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(dummy, del);
	}
}
/*
void	ft_del(void *content)
{
	free(content);
}
#include <stdio.h>
int	main()
{
	t_list *head = NULL;
	t_list	*curr = NULL;
	char	*data[] = {"one", "two", "three", "four"};

	for (int i = 0; i < 4; i++)
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(data[i])));
	ft_lstclear(&(head->next->next), &ft_del);
	for (curr = head; curr; curr = curr->next)
		printf("content : %s\n", (char *)curr->content);
	ft_lstclear(&head, &ft_del);
	return (0);
}
*/