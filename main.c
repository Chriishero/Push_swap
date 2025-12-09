/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 06:50:46 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/09 08:01:49 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_args.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_args(argc, argv);
	a = init_stack(argv, argc);
	b = NULL;
	push_swap(&a, &b, get_strategy(argv, argc), isbenchmark_flag(argv, argc));
	/*for (t_stack curr = a; curr; curr = curr->next)
		ft_printf("%d\n", curr->content);*/
	return (0);
}
