/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:36:19 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/17 23:32:28 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

int	check_number(char *nbr)
{
	int	i;

	if (ft_atol(nbr) > INT_MAX || ft_atol(nbr) < INT_MIN)
		return (FAILURE);
	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (!ft_isdigit(nbr[i + 1]))
			return (FAILURE);
		i++;
	}
	while (i < ft_strlen(nbr))
	{
		if (!ft_isdigit(nbr[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_list(char *list)
{
	char	**elements;
	int		i;

	if (ft_strchr(list, '\n'))
		elements = ft_split(list, '\n');
	else
		elements = ft_split(list, ' ');
	if (!elements)
		return (FAILURE);
	if (check_duplicate(elements) == FAILURE)
		return (free_after_split(elements), FAILURE);
	i = -1;
	while (++i >= 0 && elements[i])
	{
		if (check_number(elements[i]) == FAILURE)
			return (free_after_split(elements), FAILURE);
	}
	return (free_after_split(elements), SUCCESS);
}

int	check_modes(int argc, char **argv)
{
	int	isbench;
	int	isstrat;

	isbench = FALSE;
	isstrat = FALSE;
	while (--argc > 0)
	{
		if (are_strs_equals(argv[argc], "--simple") && isstrat == FALSE)
			isstrat = TRUE;
		else if (are_strs_equals(argv[argc], "--medium") && isstrat == FALSE)
			isstrat = TRUE;
		else if (are_strs_equals(argv[argc], "--complex")
			&& isstrat == FALSE)
			isstrat = TRUE;
		else if (are_strs_equals(argv[argc], "--adaptive")
			&& isstrat == FALSE)
			isstrat = TRUE;
		else if (are_strs_equals(argv[argc], "--bench") && isbench == FALSE)
			isbench = TRUE;
		else if (ft_strncmp(argv[argc], "--", 2) == 0)
			return (FAILURE);
	}
	if (isstrat || isbench)
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
	if (is_mode == FAILURE
		|| (check_duplicate(&argv[1]) == FAILURE))
		error();
	i = 0;
	if (ft_strncmp(argv[argc - 1], "--", 2) == 0)
		error();
	while (++i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
		{
			list = argv[i];
			if (check_list(argv[i]) == FAILURE)
				error();
		}
	}
	if (!list)
		error();
}
