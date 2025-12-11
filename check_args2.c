/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:18:13 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/11 01:26:20 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

static int	check_duplicates_btw_tabs(char **tab1, char **tab2)
{
	int	i;

	if (!tab1 || !tab2)
		return (FAILURE);
	while (*tab1)
	{
		i = 0;
		while (tab2[i])
		{
			if (ft_atoi(*tab1) == ft_atoi(tab2[i]))
				return (FAILURE);
			i++;
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
	i = -1;
	while (ft_strncmp(tab[i + 1], "--", 2) == 0)
		i++;
	while (++i >= 0 && tab[i])
	{
		first_split = ft_split(tab[i], ' ');
		k = i;
		while (++k > i && tab[k])
		{
			second_split = ft_split(tab[k], ' ');
			if (check_duplicates_btw_tabs(first_split, second_split) == FAILURE)
				return (free_after_split(first_split),
					free_after_split(second_split), FAILURE);
			free_after_split(second_split);
		}
		free_after_split(first_split);
	}
	return (SUCCESS);
}
