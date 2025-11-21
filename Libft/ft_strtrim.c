/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:58:38 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/11 19:52:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimed_str;
	int		i;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen((char *)s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	trimed_str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimed_str)
		return (NULL);
	i = 0;
	while (start <= end)
		trimed_str[i++] = s1[start++];
	trimed_str[i] = '\0';
	return (trimed_str);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_strtrim("  qwerty helloqwertyworld  !!?! qwer ", "qwerty "));
	return (0);
}
*/