/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 06:25:42 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/12 09:07:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countword(const char *s, char delimiter)
{
	int	count;
	int	isword;

	if (s == NULL)
		return (-1);
	count = 0;
	isword = 0;
	while (*s)
	{
		if (*s != delimiter && !isword)
		{
			isword = 1;
			count++;
		}
		else if (*s == delimiter)
			isword = 0;
		s++;
	}
	return (count);
}

static char	*ft_getword(char const *s, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char	const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		start;

	array = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!array || ft_countword(s, c) == -1)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[j++] = ft_getword(s + start, i - start);
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
/*
int	main()
{
    char    *s = "ihidshfiasdhfdisafyuiopoio fdosaofdsoafo ufdsaof fdsaf o";
    char    c = 'o';
	char	**split = ft_split(s, c);

	for (int i = 0; split != NULL && split[i]; i++)
	{
		printf("%s\n", split[i]);
		free(split[i]);
	}
	free(split);
	return (0);
}
*/