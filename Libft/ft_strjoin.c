/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:50:04 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/11 18:57:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*join;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = (char *)malloc((total_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_strjoin("hello", " world"));
	return (0);
}*/
