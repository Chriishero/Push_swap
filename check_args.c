/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:36:19 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/03 09:43:51 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

int	check_number(char *nbr)
{
	int	i;

	if (ft_atol(nbr) > INT_MAX || ft_atol(nbr) < INT_MIN)
		return (FAILURE);
	i = 0;
	while (++i >= 0 && nbr[i])
	{
		if (((nbr[i] == '-' || nbr[i] == '+') && !ft_isdigit(nbr[i + 1]))
			|| (nbr[i] != '-' && nbr[i] != '+' && !ft_isdigit(nbr[i])))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_list(char *list)
{
	char	**elements;
	int		i;
	int		k;

	elements = ft_split(list, ' ');
	if (!elements)
		return (FAILURE);
	i = 0;
	while (elements[i])
	{
		k = i + 1;
		while (elements[k])
		{
			if (ft_atoi(elements[i]) == ft_atoi(elements[k]))
				return (free_after_split(elements), FAILURE);
			k++;
		}
		if (check_number(elements[i]) == FAILURE)
			return (free_after_split(elements), FAILURE);
		i++;
	}
	return (free_after_split(elements), SUCCESS);
}

int	check_modes(int argc, char **argv)
{
	int	i;
	int	isbench;
	int	isstrategy;

	isbench = FALSE;
	isstrategy = FALSE;
	i = 0;
	while (++i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0 && isstrategy == FALSE)
			isstrategy = TRUE;
		if (ft_strncmp(argv[i], "--medium", 9) == 0 && isstrategy == FALSE)
			isstrategy = TRUE;
		if (ft_strncmp(argv[i], "--complex", 10) == 0 && isstrategy == FALSE)
			isstrategy = TRUE;
		if (ft_strncmp(argv[i], "--adaptive", 10) == 0 && isstrategy == FALSE)
			isstrategy = TRUE;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0 && isbench == FALSE)
			isbench = TRUE;
		else if (ft_strncmp(argv[i], "--", 2) == 0)
			return (FAILURE);
	}
	if (isstrategy || isbench)
		return (TRUE);
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
	is_mode = check_modes(argc, argv);
	if (is_mode == FAILURE)
		error();
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
