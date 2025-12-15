/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:49:54 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/16 00:47:06 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// selection sorting
t_monitoring	simple_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	selection_sorting_a(a, b, &find_min_index, m);
	while (*b)
		m.n_pa += do_p(b, a, 'a');
	return (m);
}
