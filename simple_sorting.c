/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:49:54 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/11 09:19:05 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	i;
	int	min_idx;
	int	min;

	if (!a)
		return (FAILURE);
	i = 0;
	min_idx = INT_MAX;
	min = a->content;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			min_idx = i;
		}
		a = a->next;
		i++;
	}
	return (min_idx);
}

// insertion sorting
t_monitoring	simple_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	int				size;
	int				idx;
	int				moves;

	while (*a)
	{
		size = stack_size(*a);
		idx = find_min_index(*a);
		if (idx == FAILURE)
			break ;
		if (idx <= size / 2)
			while (idx-- > 0)
				m.n_ra += do_r(a, 'a');
		else
		{
			moves = size - idx;
			while (moves-- > 0)
				m.n_rra += do_rr(a, 'a');
		}
		m.n_pb += do_p(a, b, 'b');
	}
	while (*b)
		m.n_pa += do_p(b, a, 'a');
	return (m);
}
