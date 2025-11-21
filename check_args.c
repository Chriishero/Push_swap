/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:36:19 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 08:59:52 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

int	check_list(char *list)
{
	char	**elements;
	int		i;

	if (!list)
		return (FAILURE);
	elements = ft_split(list, ' ');
	if (!elements)
		return (FAILURE);
	i = 0;
	while (elements[i])
	{
		while (*elements[i])
		{
			if (!ft_isdigit(*elements[i]))
			{
				free_after_split(elements);
				return (FAILURE);
			}
			*elements[i]++;
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
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--complexe", 10) == 0)
			return (TRUE);
		else if (ft_strncmp(argv[i], "--bench", 7) == 0)
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

	if (!argv || !*argv)
		error();
	is_mode = FALSE;
	if (check_modes(argc, argv))
		is_mode = TRUE;
	i = 1;
	while (i < argc)
	{
		if (is_mode && ft_strncmp(argv[i], "--", 2) != 0)
		{
			if (check_list(argv[i]) == FAILURE || i + 1 < argc)
				error();
		}
		else if (!is_mode)
			if (check_list(argv[i]) == FAILURE)
				error();
		i++;
	}
}
