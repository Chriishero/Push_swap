/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:15:59 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 08:01:42 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	swap_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
}

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*first;
	t_stack	*second;

	if (!s1 || !*s1 || !s2 || !*s2)
		return ;
	first = *s1;
	second = first->next;
	first->next = *s2;
	*s1 = second;
	*s2 = first;
}
