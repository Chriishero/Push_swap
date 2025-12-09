/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:15:59 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/09 08:00:17 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return (0);
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
	return (1);
}

int	swap_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return (0);
	if (!b || !*b || !(*b)->next)
		return (0);
	swap(a);
	swap(b);
	return (ft_printf("ss\n"), 1);
}

int	do_s(t_stack **s, char c)
{
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	return (swap(s));
}
