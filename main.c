/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:50:46 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 09:33:47 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_args.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*curr;

	check_args(argc, argv);
	a = init_stack(argv, argc);
	b = NULL;
	push_swap(&a, &b, get_strategy(argv, argc), isbenchmark_flag(argv, argc));
	for (curr = a; curr; curr = curr->next)
		ft_printf("%d\n", curr->content);
	return (0);
}
