/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:01:19 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:29:02 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *a)
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

int	find_min_index(t_stack *a)
{
	int	i;
	int	min_idx;
	int	min;

	if (!a)
		return (FAILURE);
	i = 0;
	min_idx = 0;
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

t_monitoring	selection_sorting_a(t_stack **a, t_stack **b, t_monitoring m)
{
	int				size;
	int				idx;
	int				moves;

	while (*a)
	{
		size = stack_size(*a);
		idx = find_max_index(*a);
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
	return (m);
}

t_monitoring	selection_sorting_b(t_stack **b, t_stack **a, t_monitoring m)
{
	int				size;
	int				idx;
	int				moves;

	while (*b)
	{
		size = stack_size(*b);
		idx = find_max_index(*b);
		if (idx == FAILURE)
			break ;
		if (idx <= size / 2)
			while (idx-- > 0)
				m.n_rb += do_r(b, 'b');
		else
		{
			moves = size - idx;
			while (moves-- > 0)
				m.n_rrb += do_rr(b, 'b');
		}
		m.n_pa += do_p(b, a, 'a');
	}
	return (m);
}
