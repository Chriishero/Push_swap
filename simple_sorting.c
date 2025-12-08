/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:49:54 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/08 23:55:12 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *a)
{
	int	i;
	int	max_idx;
	int	max;

	if (!a)
		return (FAILURE);
	i = 0;
	max_idx = 0;
	max = a->content;
	while (a)
	{
		if (a->content > max)
		{
			max = a->content;
			max_idx = i;
		}
		a = a->next;
		i++;
	}
	return (max_idx);
}

// selection sorting
t_monitoring	simple_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	int				idx;
	int				moves;

	while (*a)
	{
		idx = find_max_index(*a);
		if (idx == FAILURE)
			break ;
		if (idx <= stack_size(*a) / 2)
			while (idx-- > 0)
				m.n_ra += rotate(a);
		else
		{
			moves = stack_size(*a) - idx;
			while (moves-- > 0)
				m.n_rra += reverse_rotate(a);
		}
		m.n_pb += push(a, b);
		m.n_rb += rotate(b);
	}
	while (*b)
		m.n_pa += push(b, a);
	return (m);
}
