/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:50:46 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/25 09:55:09 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_args.h"

t_stack *new_stack(int start, int len)
{
	t_stack *s;
	t_stack *new;
	t_stack *curr;

	s = NULL;
	for (int i = start; i < start + len; i++)
    {
        new = malloc(sizeof(t_stack));
        if (!new)
            return (NULL);
        new->content = i;
        new->next = NULL;
        if (!s)
            s = new;
        else
            curr->next = new;
        curr = new;
    }
	return (s);
}

int main(int argc, char **argv)
{
    // t_stack *a = NULL;
    // t_stack *b = NULL;
	// t_stack *curr;
	
    // a = new_stack(0, 1);
	// b = new_stack(10, 6);
    // reverse_rotate_ss(&a, &b);
	// curr = b;
	// for (; curr; curr = curr->next)
	// 	ft_printf("%d\n", curr->content);
	t_stack	*stack;
	t_stack *curr;

	check_args(argc, argv);
	stack = init_stack(argv, argc);
	for (curr = stack; curr; curr = curr->next)
		ft_printf("%d\n", curr->content);
    return (0);
}
