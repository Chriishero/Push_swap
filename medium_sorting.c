/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:51:20 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/11 10:26:21 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_monitoring	next_value_to_top(t_stack **a, t_monitoring m,
	int hold_first, int hold_second)
{
	if (stack_size(*a) - hold_second + 1 < hold_first)
		while (stack_size(*a) - ++hold_second > 0)
			m.n_rra += do_rr(a, 'a');
	else
		while (--hold_first > 0)
			m.n_rra += do_r(a, 'a');
	return (m);
}

static int	find_value_in_chunk(t_stack *a, int min, int max, int istop)
{
	int	i;
	int	idx;

	if (!a)
		return (FAILURE);
	i = 0;
	idx = FAILURE;
	while (a)
	{
		if (a->content >= min && a->content <= max)
		{
			if (istop == TRUE)
				return (i);
			else
				idx = i;
		}
		i++;
		a = a->next;
	}
	return (idx);
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
		tabs[index++] = i;
		curr = curr->next;
	}
	return (tabs);
}

void	replace_content_by_index(t_stack **a, int *indexs)
{
	t_stack	*curr;
	int		i;

	curr = *a;
	i = 0;
	while (curr)
	{
		curr->content = indexs[i];
		curr = curr->next;
		i++;
	}
}

t_monitoring	medium_sorting(t_stack **a, t_stack **b, t_monitoring m)
// chunks sorting
{
	int	*indexs;
	int	n_chunks;
	int	curr_chunk;
	int	hold_first;
	int	hold_second;

	indexs = value_to_index(*a);
	replace_content_by_index(a, indexs);
	n_chunks = ft_sqrt(stack_size(*a));
	curr_chunk = 0;
	while (curr_chunk < n_chunks)
	{
		hold_first = find_value_in_chunk(*a, n_chunks * curr_chunk,
				n_chunks * curr_chunk + n_chunks, TRUE) + 1;
		if (hold_first - 1 == FAILURE)
			curr_chunk++;
		else
		{
			hold_second = find_value_in_chunk(*a, n_chunks * curr_chunk,
					n_chunks * curr_chunk + n_chunks, FALSE) - 1;
			m = next_value_to_top(a, m, hold_first, hold_second);
			m.n_pb += do_p(a, b, 'b');
		}
	}
	return (free(indexs), selection_sorting(a, b, m));
}
