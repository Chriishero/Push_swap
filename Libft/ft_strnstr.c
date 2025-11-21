/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:06:30 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/11 19:28:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] && little[j] && big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)&big[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_strnstr("aaaaaa", "", 20));
	return (0);
}*/
