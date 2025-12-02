/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:51:20 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/02 23:11:30 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(int *tabs)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (tabs[i])
	{
		if (max < tabs[i])
			max = tabs[i];
		i++;
	}
	return (max);
}

static int	*value_to_index(t_stack *a)
{
	int		*tabs;
	t_stack	*curr;
	t_stack	*compare;
	int		i;
	int		index;

	tabs = (int *)malloc(sizeof(int) * (stack_size(a) + 1));
	if (!tabs)
		return (NULL);
	curr = a;
	index = 0;
	while (curr)
	{
		i = 0;
		compare = a;
		while (compare)
		{
			if (compare->content < curr->content)
				i++;
			compare = compare->next;
		}
		tabs[index] = i;
		curr = curr->next;
		index++;
    }
	tabs[index] = NULL;
	return (tabs);
}

void	replace_content_by_index(t_stack **a, int *indexs)
{
	t_stack	*curr;
	int 	i;

	curr = *a;
	i = 0;
	while (curr)
	{
		curr->content = indexs[i];
		curr = curr->next;
		i++;
	}
}

t_monitoring medium_sorting(t_stack **a, t_stack **b) // chunks sorting
{
	t_monitoring	m;
	int				*indexs;
	int				n_chunks;
	int				curr_chunk;
	int				chunk_index;

	m = (t_monitoring){0};
	indexs = value_to_index(*a);
	replace_content_by_index(a, indexs);
	n_chunks = ft_sqrt(stack_size(*a));
	curr_chunk = 0;
	chunk_index = 0;
	while (curr_chunk < n_chunks && stack_size(*a) > 0)
	{
		if (chunk_index >= n_chunks - 1)
		{
			curr_chunk++;
			chunk_index = 0;
		}
		if ((*a)->content / n_chunks == curr_chunk)
		{
			m.n_pb = push(a, b);
			chunk_index++;
		}
		else
			m.n_ra = rotate(a);
	}
	while (stack_size(*b) > 0)
	{
		
	}
}