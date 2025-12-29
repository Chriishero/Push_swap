/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_n_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:56:13 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/29 22:26:33 by cvillene         ###   ########.fr       */
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
	int	max_idx;
}
