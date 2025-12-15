/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 06:02:04 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:57:52 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	rotate(t_stack **s)
{
	t_stack	*curr;
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return (0);
	curr = *s;
	first = curr;
	second = first->next;
	while (curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
	*s = second;
	return (1);
}

int	rotate_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return (0);
	rotate(a);
	rotate(b);
	ft_printf_fd(1, "rr\n");
	return (1);
}

int	do_r(t_stack **s, char c)
{
	if (c == 'a' || c == 'b')
		ft_printf_fd(1, "r%c\n", c);
	return (rotate(s));
}
