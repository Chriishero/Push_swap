/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:22:23 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/17 23:36:17 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	are_strs_equals(char *str1, char *str2)
{
	int	size;

	if (!str1 && !str2)
		return (TRUE);
	else if (!str1 || !str2)
		return (FALSE);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (FALSE);
	size = ft_strlen(str1);
	if (ft_strncmp(str1, str2, size) != 0)
		return (FALSE);
	return (TRUE);
}
