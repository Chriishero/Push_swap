/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:12:12 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/26 07:19:18 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H
# include "utils.h"

typedef struct s_monitoring
{
	int	n_sa;
	int	n_sb;
	int	n_ss;
	int	n_pa;
	int	n_pb;
	int	n_ra;
	int	n_rb;
	int	n_rr;
	int	n_rra;
	int	n_rrb;
	int	n_rrr;
}		t_monitoring;

#endif