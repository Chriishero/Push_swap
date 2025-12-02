/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:52:37 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/02 23:24:41 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils.h"
# include "benchmark.h"

void			push_swap(t_stack **a, t_stack **b,
					char *strategy, int isbenchmark);
t_monitoring	simple_sorting(t_stack **a, t_stack **b);
t_monitoring	medium_sorting(t_stack **a, t_stack **b);
t_monitoring	complex_sorting(t_stack **a, t_stack **b);
t_monitoring	adaptive_sorting(t_stack **a, t_stack **b);

#endif