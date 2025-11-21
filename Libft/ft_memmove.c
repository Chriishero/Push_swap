/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 05:34:50 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/06 07:59:34 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	if (ptr_s > ptr_d)
	{
		i = -1;
		while (++i < n)
			ptr_d[i] = ptr_s[i];
	}
	else if (ptr_d > ptr_s)
	{
		i = n + 1;
		while (--i > 0)
			ptr_d[i - 1] = ptr_s[i - 1];
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char str[] = "abcdefghij";
	
	memcpy(str + 1, str, 3);
	printf("%s", str);
	return (0);
}*/
