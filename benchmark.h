/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:12:12 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/08 23:25:41 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H
# include "utils.h"

typedef struct s_monitoring
{
	char	*strategy;
	char	*time_order;
	int		disorder;
	int		n_sa;
	int		n_sb;
	int		n_ss;
	int		n_pa;
	int		n_pb;
	int		n_ra;
	int		n_rb;
	int		n_rr;
	int		n_rra;
	int		n_rrb;
	int		n_rrr;
}		t_monitoring;

t_monitoring	add_monitoring(t_monitoring m1, t_monitoring m2);
int				compute_disorder(t_stack *s);
int				compute_total_ops(t_monitoring m);
void			print_benchmark(t_monitoring m);

#endif