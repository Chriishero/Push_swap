/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:49:54 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:15:30 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
