/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:30:41 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 09:54:52 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_monitoring	complex_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	push(a, b);
	push(b, a);
	return (m);
}
