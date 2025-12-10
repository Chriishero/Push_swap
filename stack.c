/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 07:13:24 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/11 00:09:26 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

// static int	count_element(char *list)
// {
// 	int	i;
// 	int	count;
// 	int	iselement;

// 	i = 0;
// 	count = 0;
// 	iselement = 0;
// 	while (list[i])
// 	{
// 		if (list[i] == ' ' && iselement == 1)
// 			iselement = 0;
// 		else if (list[i] != ' ' && iselement == 0)
// 		{
// 			iselement = 1;
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

static char	*join_args(char *elements, const char *arg)
{
	char	*tmp;
	char	*tmp2;
	
	tmp = ft_strjoin(elements, arg);
	if (!tmp)
		return (free(elements), NULL);
	free(elements);
	tmp2 = ft_strjoin(tmp, " ");
	if (!tmp2)
		return (free(tmp), NULL);
	free(tmp);
	return (tmp2);	
}

static char	**init_tab(char **argv, int argc)
{
	int		i;
	char	**tab;
	char	*elements;

	i = 1;
	while (argv[i] && ft_strnstr(argv[i], "--", 2))
		i++;
	elements = ft_strdup("");
	while (i < argc)
	{
		elements = join_args(elements, argv[i]);
		if (!elements)
			return (NULL);
		i++;
	}
	tab = ft_split(elements, ' ');
	free(elements);
	if (!tab)
		return (free_after_split(tab), NULL);
	return (tab);
}

t_stack	*init_stack(char **argv, int argc)
{
	char	**tab;
	int		i;
	t_stack	*s;
	t_stack	*new;
	t_stack	*curr;

	tab = init_tab(argv, argc);
	if (!tab)
		return (NULL);
	s = NULL;
	i = -1;
	while (++i >= 0 && tab[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (free_after_split(tab), NULL);
		new->content = ft_atoi(tab[i]);
		new->next = NULL;
		if (!s)
			s = new;
		else
			curr->next = new;
		curr = new;
	}
	return (free_after_split(tab), s);
}

void	free_stack(t_stack *s)
{
	t_stack *dummy;

	while (s)
	{
		dummy = s->next;
		free(s);
		s = dummy;
	}
}
