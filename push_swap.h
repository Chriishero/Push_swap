/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:52:37 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 07:13:14 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "utils.h"

void	push_swap(t_stack **a, t_stack **b, char *strategy);
void	simple_sorting(t_stack **a, t_stack **b);
void	medium_sorting(t_stack **a, t_stack **b);
void	complex_sorting(t_stack **a, t_stack **b);

#endif