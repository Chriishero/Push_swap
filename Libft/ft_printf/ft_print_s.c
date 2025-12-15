/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:53:37 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:53:20 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_s(char *s, int fd)
{
	char	*str;
	int		strlen;

	if (!s)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	ft_putstr_fd(str, fd);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
