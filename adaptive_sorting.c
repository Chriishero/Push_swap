/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:41:25 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/29 22:24:51 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_monitoring	adaptive_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	if (m.disorder < 0.2 * 10000)
		m = simple_sorting(a, b, m);
	else if (m.disorder >= 0.2 * 10000 && m.disorder < 0.5 * 10000)
		m = medium_sorting(a, b, m);
	else if (m.disorder >= 0.5 * 10000)
		m = complex_sorting(a, b, m);
	return (m);
}
