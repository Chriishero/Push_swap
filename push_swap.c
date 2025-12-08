/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:59:55 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/08 23:11:47 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_strategy(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
			if (ft_strncmp(argv[i], "--bench", 10) != 0)
				return (argv[i]);
		i++;
	}
	return (NULL);
}

int	isbenchmark_flag(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 10) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_monitoring	adaptive_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	if (m.disorder < 0.2)
		m = simple_sorting(a, b, m);
	else if (m.disorder >= 0.2 && m.disorder < 0.5)
		m = medium_sorting(a, b, m);
	else if (m.disorder >= 0.5)
		m = complex_sorting(a, b, m);
	return (m);
}

void	push_swap(t_stack **a, t_stack **b, char *strategy, int isbenchmark)
{
	t_monitoring	m;

	m = (t_monitoring){0};
	m.disorder = compute_disorder(*a);
	if (!strategy || ft_strncmp(strategy, "--adaptive", 13) == 0)
		m = adaptive_sorting(a, b, m);
	else if (ft_strncmp(strategy, "--simple", 10) == 0)
		m = simple_sorting(a, b, m);
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		m = medium_sorting(a, b, m);
	else if (ft_strncmp(strategy, "--complex", 9) == 0)
		m = complex_sorting(a, b, m);
	if (isbenchmark == TRUE)
		print_benchmark(m, strategy);
}
