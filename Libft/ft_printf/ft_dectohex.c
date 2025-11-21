/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:56:39 by marvin            #+#    #+#             */
/*   Updated: 2025/11/18 13:56:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dectohex_unsigned(unsigned long n, int islower)
{
	char	*result;
	char	*hex_array;
	int		i;

	result = (char *)malloc(ft_nbrlen_unsigned(n) + 1);
	if (!result)
		return (NULL);
	if (islower == 1)
		hex_array = "0123456789abcdef";
	else
		hex_array = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		result[i++] = '0';
	while (n != 0)
	{
		result[i++] = hex_array[n % 16];
		n /= 16;
	}
	result[i] = '\0';
	return (ft_reversestr(&result[0]));
}

char	*ft_dectohex_signed(long long n, int islower)
{
	char	*result;
	char	*hex_array;
	int		i;

	result = (char *)malloc(ft_nbrlen_signed(n) + 1);
	if (!result)
		return (NULL);
	if (islower == 1)
		hex_array = "0123456789abcdef";
	else
		hex_array = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		result[i++] = '0';
	while (n != 0)
	{
		if (n % 16 < 0)
			result[i++] = hex_array[n % 16 * -1];
		else
			result[i++] = hex_array[n % 16];
		n /= 16;
	}
	result[i] = '\0';
	return (ft_reversestr(&result[0]));
}
