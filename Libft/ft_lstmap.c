/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:36 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 15:44:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!new_element)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	*ft_f(void *content)
{
	const char	*p;
	char		*dup;
	int			i;

	p = content;
	dup = ft_strdup(p);
	i = 0;
	while (dup[i])
	{
		if (dup[i] >= 'a' && dup[i] <= 'z')
			dup[i] -= 32;
		i++;
	}
	return (dup);
}
void	ft_del(void	*content)
{
	free(content);
}
#include <stdio.h>
int	main()
{
	t_list	*head = NULL;
	t_list	*new_list = NULL;
	t_list	*curr = NULL;
	char	*data[] = { "one", "two", "three", "four" };

	for(int i = 0; i < 4; i++)
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(data[i])));
	new_list = ft_lstmap(head->next, &ft_f, &ft_del);
	for (curr = new_list; curr; curr = curr->next)
		printf("new_list content : %s\n", (char *)curr->content);
	ft_lstclear(&new_list, &ft_del);
	return (0);
}*/