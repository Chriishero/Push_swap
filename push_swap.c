/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:59:55 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 09:50:08 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*simple_sorting(t_stack **a, t_stack **b) // insertion sorting
{
	char	*ops;
	t_stack	*curr;
	t_stack *dummy;

	ops = ft_strdup("");
	if (!ops)
		return (free(ops), NULL);
	curr = a;
	while (curr)
	{
		
	}
	return (ops);
}

void	push_swap(t_stack **a, t_stack **b, char *strategy, int isbenchmark)
{
	char	*operations;
	char	**tab;
	
	if (ft_strncmp(strategy, "--simple", 9))
		operations = simple_sorting(a, b);
	else if (ft_strncmp(strategy, "--medium", 9))
		operations = medium_sorting(a, b);
	else if (ft_strncmp(strategy, "--complex", 9))
		operations = complex_sorting(a, b);
	else if (!strategy || ft_strncmp(strategy, "--adaptive", 13))
		operations = adaptive_sorting(a, b);
}