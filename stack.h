/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:09:41 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/09 07:59:31 by cvillene         ###   ########.fr       */
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
// do operation
int		swap(t_stack **s);
int		swap_ss(t_stack **a, t_stack **b);
int		push(t_stack **s1, t_stack **s2);
int		rotate(t_stack **s);
int		rotate_ss(t_stack **a, t_stack **b);
int		reverse_rotate(t_stack **s);
int		reverse_rotate_ss(t_stack **a, t_stack **b);
// handle operation (do and print)
int		do_s(t_stack **s, char c);
int		do_p(t_stack **a, t_stack **b, char c);
int		do_r(t_stack **s, char c);
int		do_rr(t_stack **s, char c);

#endif