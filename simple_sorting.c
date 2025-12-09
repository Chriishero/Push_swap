/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:49:54 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/09 08:06:07 by cvillene         ###   ########.fr       */
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
				m.n_ra += do_r(a, 'a');
		else
		{
			moves = stack_size(*a) - idx;
			while (moves-- > 0)
				m.n_rra += do_rr(a, 'a');
		}
		m.n_pb += do_p(a, b, 'b');
		m.n_rb += do_r(b, 'b');
	}
	while (*b)
		m.n_pa += do_p(b, a, 'a');
	return (m);
}
