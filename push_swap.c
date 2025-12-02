/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:59:55 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/02 07:51:50 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, char *strategy, int isbenchmark)
{
	t_monitoring	m;

	if (ft_strncmp(strategy, "--simple", 10) == 0)
		m = simple_sorting(a, b);
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		m = medium_sorting(a, b);
	// else if (ft_strncmp(strategy, "--complex", 9))
	// 	m = complex_sorting(a, b);
	// else if (!strategy || ft_strncmp(strategy, "--adaptive", 13))
	// 	m = adaptive_sorting(a, b);
	if (isbenchmark == TRUE)
		ft_printf("ra: %d\nrb: %d\nrra: %d\nrrb: %d\npa: %d\npb: %d\n",
			m.n_ra, m.n_rb, m.n_rra, m.n_rrb, m.n_pa, m.n_pb);
}
