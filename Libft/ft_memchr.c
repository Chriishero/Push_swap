/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:34:53 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/13 09:13:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	const unsigned int size = 10;

    void * found = ft_memchr( data, 57, size );
    printf( "57 %s\n", ( found != NULL ? "ya" : "nah" ) );
	found = ft_memchr( data, 50, size );
	printf( "50 %s\n", ( found != NULL ? "ya" : "nah" ) );
	if ( found != NULL ) {
		printf( "valeur :  %d\n", (*(char *) found) );
	}
	return (0);
}*/
