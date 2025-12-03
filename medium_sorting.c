/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:51:20 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 09:57:15 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_stack *s)
{
	int	max;

	max = INT_MIN;
	while (s)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

static t_monitoring	chunks_sorting(t_stack **a, t_stack **b)
{
	t_monitoring	m;
	int				max_idx;
	
	m = (t_monitoring){0};
	max_idx = stack_size(*b);
	while (stack_size(*b) >= 0)
	{
		while ((*b)->content != max_idx)
			m.n_rb += rotate(b);
		m.n_pa += push(b, a);
		max_idx--;
	}
	return (m);
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

t_monitoring medium_sorting(t_stack **a, t_stack **b, t_monitoring m) // chunks sorting
{
	int				*indexs;
	int				n_chunks;
	int				curr_chunk;
	int				chunk_index;

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
			m.n_pb += push(a, b);
			chunk_index++;
		}
		else
			m.n_ra += rotate(a);
	}
	m = chunks_sorting(a, b);
	return (m);
}