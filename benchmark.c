/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:17:26 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 10:02:41 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

t_monitoring	add_monitoring(t_monitoring m1, t_monitoring m2)
{
	m1.n_pa += m2.n_pa;
	m1.n_pb += m2.n_pa;
	m1.n_ra += m2.n_ra;
	m1.n_rb += m2.n_rb;
	m1.n_rr += m2.n_rr;
	m1.n_rra += m2.n_rra;
	m1.n_rrb += m2.n_rrb;
	m1.n_rrr += m2.n_rrr;
	m1.n_sa += m2.n_sa;
	m1.n_sb += m2.n_sb;
	m1.n_ss += m2.n_ss;
	return (m1);
}

int	compute_disorder(t_stack *s)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*curr;
	t_stack	*next;

	mistakes = 0;
	total_pairs = 0;
	curr = s;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			total_pairs++;
			if (curr->content > next->content)
				mistakes++;
			next = next->next;
		}
		curr = curr->next;
	}
	return (mistakes / total_pairs);
}

void	print_benchmark(t_monitoring m, char *strategy)
{
	ft_printf("[bench] disorder:	%d", m.disorder);
	if (!strategy || ft_strncmp(strategy, "--adaptive", 13) == 0)
		ft_printf("[bench] strategy:	Adaptive / O(n^2)");
	else if (ft_strncmp(strategy, "--simple", 10) == 0)
		ft_printf("[bench] strategy:	Simple / O(n^2)");
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		ft_printf("[bench] strategy:	Medium / O(nsqrt(n))");
	else if (ft_strncmp(strategy, "--complex", 9) == 0)
		ft_printf("[bench] strategy:	Complex / O(nlog(n))");
}
