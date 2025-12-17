/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:30:41 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/17 07:38:59 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nbr_of_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) != 0)
		bits++;
	return (bits);
}

static int	*value_to_index(t_stack *a)
{
	int		*tabs;
	t_stack	*curr;
	t_stack	*compare;
	int		i;
	int		index;

	tabs = (int *)malloc(sizeof(int) * (stack_size(a)));
	if (!tabs)
		return (NULL);
	curr = a;
	index = 0;
	while (curr)
	{
		i = 0;
		compare = a;
		while (compare)
		{
			if (compare->content < curr->content)
				i++;
			compare = compare->next;
		}
		tabs[index++] = i;
		curr = curr->next;
	}
	return (tabs);
}

static void	replace_content_by_index(t_stack **a, int *indexs)
{
	t_stack	*curr;
	int		i;

	curr = *a;
	i = 0;
	while (curr)
	{
		curr->content = indexs[i];
		curr = curr->next;
		i++;
	}
}

t_monitoring	complex_sorting(t_stack **a, t_stack **b, t_monitoring m)
{
	int	*indexs;
	int	max_bit;
	int	curr_bit;
	int	s_size;

	indexs = value_to_index(*a);
	replace_content_by_index(a, indexs);
	max_bit = find_nbr_of_bits(find_max_element(*a));
	curr_bit = 0;
	while (curr_bit < max_bit)
	{
		s_size = stack_size(*a);
		while (s_size-- > 0)
		{
			if ((((*a)->content >> curr_bit) & 1) == 0)
				m.n_pb += do_p(a, b, 'b');
			else
				m.n_ra += do_r(a, 'a');
		}
		while (*b)
			m.n_pa += do_p(b, a, 'a');
		curr_bit++;
	}
	free(indexs);
	return (m);
}
