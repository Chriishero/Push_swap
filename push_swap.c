/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:59:55 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/26 08:22:49 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_monitoring	simple_sorting(t_stack **a, t_stack **b) // insertion sorting
{
	t_monitoring	m;
	t_stack			*curr;
	t_stack 		*dummy;

	m = (t_monitoring){0};
	curr = a;
	while (curr)
	{

	}
	return (m);
}

void	push_swap(t_stack **a, t_stack **b, char *strategy, int isbenchmark)
{
	t_monitoring	m;
	
	if (ft_strncmp(strategy, "--simple", 9))
		m = simple_sorting(a, b);
	else if (ft_strncmp(strategy, "--medium", 9))
		m = medium_sorting(a, b);
	else if (ft_strncmp(strategy, "--complex", 9))
		m = complex_sorting(a, b);
	else if (!strategy || ft_strncmp(strategy, "--adaptive", 13))
		m = adaptive_sorting(a, b);
}