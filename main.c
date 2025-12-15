/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:50:46 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/16 00:46:32 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_args.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	check_args(argc, argv);
	a = init_stack(argv, argc);
	b = NULL;
	push_swap(&a, &b, get_strategy(argv, argc), isbenchmark_flag(argv, argc));
	free_stack(a);
	return (0);
}
