/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:54:44 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/13 09:24:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
/*
#include <stdio.h>
int	main()
{
	int n = 10;
	int *tab = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		printf("%d", tab[i]);
	for (int i = 0; i < n - 1; i++)
		tab[i] = i;
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d", tab[i]);
	free(tab);
	return (0);
}
*/