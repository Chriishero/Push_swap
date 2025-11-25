/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:09:41 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 08:22:48 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "Libft/libft.h"
# include "utils.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack	*init_stack(char **argv, int argc);
void	swap(t_stack **s);
void	swap_ss(t_stack **a, t_stack **b);
void	push(t_stack **s1, t_stack **s2);
void	rotate(t_stack **s);
void	rotate_ss(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **s);
void	reverse_rotate_ss(t_stack **a, t_stack **b);

#endif