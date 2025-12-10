/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:18:13 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/10 23:42:44 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

static int	check_duplicates_btw_tabs(char **tab1, char **tab2)
{
	if (!tab1 || !tab2)
		return (FAILURE);
	while (*tab1)
	{
		while (*tab2)
		{
			if (ft_atoi(*tab1) == ft_atoi(*tab2))
				return (FAILURE);
			tab2++;
		}
		tab1++;
	}
	return (SUCCESS);
}

int	check_duplicate(char **tab)
{
	int		i;
	int		k;
	char	**first_split;
	char	**second_split;

	if (!tab || !*tab)
		return (FAILURE);
	i = 0;
	if (check_number(tab[i]) == FAILURE)
		i = 1;
	while (tab[i])
	{
		first_split = ft_split(tab[i], ' ');
		k = i + 1;
		while (tab[k])
		{
			second_split = ft_split(tab[k], ' ');
			if (check_duplicates_btw_tabs(first_split, second_split) == FAILURE)
				return (free_after_split(first_split),
					free_after_split(second_split), FAILURE);
			free_after_split(second_split);
			k++;
		}
		free_after_split(first_split);
		i++;
	}
	return (SUCCESS);
}
