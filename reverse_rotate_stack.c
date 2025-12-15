/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:54:44 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/16 00:00:13 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	reverse_rotate(t_stack **s)
{
	t_stack	*curr;
	t_stack	*last_prev;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return (0);
	curr = *s;
	while (curr->next->next)
		curr = curr->next;
	last_prev = curr;
	last = last_prev->next;
	curr->next = NULL;
	last->next = *s;
	*s = last;
	return (1);
}

int	reverse_rotate_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return (0);
	reverse_rotate(a);
	reverse_rotate(b);
	return (ft_printf_fd(1, "rrr\n"), 1);
}

int	do_rr(t_stack **s, char c)
{
	if (c == 'a' || c == 'b')
		ft_printf_fd(1, "rr%c\n", c);
	return (reverse_rotate(s));
}
