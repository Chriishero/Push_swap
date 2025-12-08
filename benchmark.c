/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:17:26 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/08 23:17:38 by cvillene         ###   ########.fr       */
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
	return (mistakes * 10000 / total_pairs);
}

int	compute_total_ops(t_monitoring m)
{
	int	total_ops;

	total_ops = 0;
	total_ops += m.n_pa;
	total_ops += m.n_pa;
	total_ops += m.n_ra;
	total_ops += m.n_rb;
	total_ops += m.n_rr;
	total_ops += m.n_rra;
	total_ops += m.n_rrb;
	total_ops += m.n_rrr;
	total_ops += m.n_sa;
	total_ops += m.n_sb;
	total_ops += m.n_ss;
	return (total_ops);
}

void	print_benchmark(t_monitoring m, char *strategy)
{	
	ft_printf("[bench] disorder:  %d.%d%%\n", m.disorder / 100, m.disorder % 100);
	if (!strategy || ft_strncmp(strategy, "--adaptive", 13) == 0)
		ft_printf("[bench] strategy:  Adaptive / O(n^2)\n");
	else if (ft_strncmp(strategy, "--simple", 10) == 0)
		ft_printf("[bench] strategy:  Simple / O(n^2)\n");
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		ft_printf("[bench] strategy:  Medium / O(nsqrt(n))\n");
	else if (ft_strncmp(strategy, "--complex", 9) == 0)
		ft_printf("[bench] strategy:  Complex / O(nlog(n))\n");
	ft_printf("[bench] total_ops:  %d\n", compute_total_ops(m));
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		m.n_sa, m.n_sb, m.n_ss, m.n_pa, m.n_pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n",
		m.n_ra, m.n_rb, m.n_rr, m.n_rra, m.n_rrb, m.n_rrr);
}
