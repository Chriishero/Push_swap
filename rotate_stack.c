/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 06:02:04 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 08:18:20 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **s)
{
	t_stack	*curr;
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	curr = *s;
	first = curr;
	second = first->next;
	while (curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
	*s = second;
}

void	rotate_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack **s)
{
	t_stack	*curr;
	t_stack	*last_prev;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	curr = *s;
	while (curr->next->next)
		curr = curr->next;
	last_prev = curr;
	last = last_prev->next;
	curr->next = NULL;
	last->next = *s;
	*s = last;
}

void	reverse_rotate_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}
