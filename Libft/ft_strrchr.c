/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:16:16 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/13 09:28:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	int		i;

	buf = NULL;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			buf = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (buf);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "bondour";
	printf("%s", ft_strrchr(str, 'i'));
}*/
