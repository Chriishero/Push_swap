/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:52:37 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/17 00:22:04 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils.h"
# include "benchmark.h"

void			push_swap(t_stack **a, t_stack **b,
					char *strategy, int isbenchmark);
char			*get_strategy(char **argv, int argc);
char			*get_time_order(char *strategy, int disorder);
int				isbenchmark_flag(char **argv, int argc);
// Utils
int				find_max_element(t_stack *s);
int				find_max_index(t_stack *a);
int				find_min_index(t_stack *a);
t_monitoring	selection_sorting_a(t_stack **a, t_stack **b,
					int (*find_index)(t_stack *), t_monitoring m);
t_monitoring	selection_sorting_b(t_stack **b, t_stack **a,
					int (*find_index)(t_stack *), t_monitoring m);
// Sorting algo
t_monitoring	simple_sorting(t_stack **a, t_stack **b, t_monitoring m);
t_monitoring	medium_sorting(t_stack **a, t_stack **b, t_monitoring m);
t_monitoring	complex_sorting(t_stack **a, t_stack **b, t_monitoring m);
t_monitoring	adaptive_sorting(t_stack **a, t_stack **b, t_monitoring m);

#endif