/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:41:58 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 08:42:58 by cvillene         ###   ########.fr       */
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
