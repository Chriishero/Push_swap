/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_n_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:56:13 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/29 22:52:48 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_monitoring	n_3_sorting(t_stack **a, t_monitoring m)
{
	int	min_idx;
	int	max_idx;

	if (stack_size(*a) == 2)
		m.n_sa = do_s(a, 'a');
	else
	{
		min_idx = find_min_index(*a);
		max_idx = find_max_index(*a);
		if (min_idx == 0 || (min_idx == 1 && max_idx == 0))
			m.n_ra = do_r(a, 'a');
		if (min_idx == 0 || (min_idx == 1 && max_idx == 2)
			|| (min_idx == 2 && max_idx == 0))
			m.n_sa = do_s(a, 'a');
		if (min_idx == 0 || min_idx == 2)
			m.n_rra = do_rr(a, 'a');
	}
	return (m);
}

t_monitoring	n_5_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	int	min_idx;

	while (stack_size(*a) > 3)
	{
		min_idx = find_min_index(*a);
		while (min_idx != 0)
		{
			if (min_idx >= stack_size(*a) / 2)
				m.n_rra = do_rr(a, 'a');
			else
				m.n_ra = do_r(a, 'a');
			min_idx = find_min_index(*a);
		}
		if (compute_disorder(*a) > 0)
			m.n_pb = do_p(a, b, 'b');
		else
			break ;
	}
	if (compute_disorder(*a) > 0)
		m = n_3_sorting(a, m);
	while (stack_size(*b) > 0)
		m.n_pa = do_p(b, a, 'a');
	return (m);
}
