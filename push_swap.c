/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:59:55 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/16 23:47:51 by cvillene         ###   ########.fr       */
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

char	*get_time_order(char *strategy, int disorder)
{
	if (ft_strncmp(strategy, "Simple", 10) == 0
		|| (ft_strncmp(strategy, "Adaptive", 10) == 0
			&& disorder < 0.2 * 10000))
		return (ft_strdup("O(n²)"));
	else if (ft_strncmp(strategy, "Medium", 10) == 0
		|| (ft_strncmp(strategy, "Adaptive", 10) == 0
			&& disorder >= 0.2 * 10000
			&& disorder < 0.5 * 10000))
		return (ft_strdup("O(n√n)"));
	else if (ft_strncmp(strategy, "Complex", 10) == 0
		|| (ft_strncmp(strategy, "Adaptive", 10) == 0
			&& disorder >= 0.5 * 10000))
		return (ft_strdup("O(nlog(n))"));
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
	if (m.disorder < 0.2 * 10000)
		m = simple_sorting(a, b, m);
	else if (m.disorder >= 0.2 * 10000 && m.disorder < 0.5 * 10000)
		m = medium_sorting(a, b, m);
	else if (m.disorder >= 0.5 * 10000)
		m = complex_sorting(a, b, m);
	return (m);
}

void	push_swap(t_stack **a, t_stack **b, char *strategy, int isbenchmark)
{
	t_monitoring	m;

	m = (t_monitoring){0};
	m.disorder = compute_disorder(*a);
	if (!strategy)
		m.strategy = ft_strdup("Adaptive");
	else
		m.strategy = toupper_first_letter(ft_substr(strategy, 2,
					ft_strlen(strategy) - 2));
	m.time_order = get_time_order(m.strategy, m.disorder);
	if (m.disorder > 0)
	{
		if (!strategy || ft_strncmp(strategy, "--adaptive", 13) == 0)
			m = adaptive_sorting(a, b, m);
		else if (ft_strncmp(strategy, "--simple", 10) == 0)
			m = simple_sorting(a, b, m);
		else if (ft_strncmp(strategy, "--medium", 9) == 0)
			m = medium_sorting(a, b, m);
		else if (ft_strncmp(strategy, "--complex", 9) == 0)
			m = complex_sorting(a, b, m);
	}
	if (isbenchmark == TRUE)
		print_benchmark(m);
	free(m.strategy);
	free(m.time_order);
}
