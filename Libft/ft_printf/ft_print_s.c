/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:53:37 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:55 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_s(char *s)
{
	char	*str;
	int		strlen;

	if (!s)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	ft_putstr_fd(str, 1);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
