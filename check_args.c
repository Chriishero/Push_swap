/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:36:19 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 10:18:10 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

int	check_list(char *list)
{
	char	**elements;
	int		i;
	int		j;

	if (!list)
		return (FAILURE);
	elements = ft_split(list, ' ');
	if (!elements)
		return (FAILURE);
	i = 0;
	while (elements[i])
	{
		j = 0;
		while (elements[i][j])
		{
			if (!ft_isdigit(elements[i][j]))
				return (free_after_split(elements), FAILURE);
			j++;
		}
		i++;
	}
	free_after_split(elements);
	return (SUCCESS);
}

int	check_modes(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--complexe", 10) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	char	*list;
	int		is_mode;
	int		i;

	list = NULL;
	if (!argv || !*argv)
		error();
	is_mode = FALSE;
	if (check_modes(argc, argv) == TRUE)
		is_mode = TRUE;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
		{
			list = argv[i];
			if (check_list(argv[i]) == FAILURE)
				error();
			if (is_mode == TRUE && i + 1 < argc)
				error();
		}
		i++;
	}
	if (!list)
		error();
}
