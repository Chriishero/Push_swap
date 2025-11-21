/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:10:58 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/11 19:10:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (s == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i] && (*f))
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>
// char    display_index(unsigned int index, char s)
// {
// 	if (s == 'i')
// 	{
// 			printf("%d\n", index);
// 			return '0';
// 	}
// 	return s;
// }
// #define STRING_TEST "This is a really cool string!"
// int main()
// {
//     printf("%s", ft_strmapi(STRING_TEST, &display_index));
// 	return (0);
// }