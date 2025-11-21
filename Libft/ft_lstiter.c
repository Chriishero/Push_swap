/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:28:46 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 15:28:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
}
/*
void	ft_lsttoupper(void *content)
{
	unsigned char	*p;
	int				i;

	p = content;
	i = 0;
	while (p[i])
	{
		if (p[i] >= 'a' && p[i] <= 'z')
			p[i] -= 32;
		i++;
	}
}
#include <stdio.h>
int	main()
{
	t_list	*head = NULL;
	t_list	*curr = NULL;
	char	*data[] = {"one", "two", "three", "four"};

	for (int i = 0; i < 4; i++)
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(data[i])));
	ft_lstiter(head->next, &ft_lsttoupper);
	for (curr = head; curr; curr = curr->next)
		printf("new content : %s\n", (char *)curr->content);
	curr = head;
	while (curr)
	{
		t_list *tmp = curr;
		curr = curr->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}
*/