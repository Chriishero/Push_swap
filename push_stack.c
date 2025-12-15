/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:41:58 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:58:06 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push(t_stack **s1, t_stack **s2)
{
	t_stack	*first;
	t_stack	*second;

	if (!s1 || !*s1)
		return (0);
	first = *s1;
	second = first->next;
	first->next = *s2;
	*s1 = second;
	*s2 = first;
	return (1);
}

int	do_p(t_stack **a, t_stack **b, char c)
{
	if (c == 'a' || c == 'b')
		ft_printf_fd(1, "p%c\n", c);
	return (push(a, b));
}
