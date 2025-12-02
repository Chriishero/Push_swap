/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:09:41 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/02 07:08:50 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "Libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack	*init_stack(char **argv, int argc);
int		swap(t_stack **s);
int		swap_ss(t_stack **a, t_stack **b);
int		push(t_stack **s1, t_stack **s2);
int		rotate(t_stack **s);
int		rotate_ss(t_stack **a, t_stack **b);
int		reverse_rotate(t_stack **s);
int		reverse_rotate_ss(t_stack **a, t_stack **b);

#endif