/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:19:25 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:57 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_reversestr(char *s)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i + 1])
		i++;
	j = 0;
	while (i >= 0)
		result[j++] = s[i--];
	result[j] = '\0';
	free(s);
	return (result);
}

char	*ft_ltoa(long n)
{
	int		nbr_len;
	char	*value;

	nbr_len = ft_nbrlen_signed(n);
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
