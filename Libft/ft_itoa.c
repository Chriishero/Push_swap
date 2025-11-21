/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:17:42 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/11 18:42:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nbrlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nbr_len;
	char	*value;

	nbr_len = ft_nbrlen(n);
	value = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!value)
		return (NULL);
	value[nbr_len--] = '\0';
	if (n == 0)
		value[nbr_len--] = '0';
	while (n != 0)
	{
		if (n % 10 >= 0)
			value[nbr_len--] = n % 10 + '0';
		else
			value[nbr_len--] = n % 10 * -1 + '0';
		n /= 10;
	}
	if (nbr_len == 0)
		value[nbr_len] = '-';
	return (value);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/