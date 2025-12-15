/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:38:06 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:57:06 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		check;

	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			check = ft_printargs(&args, format[++i], fd);
			if (check == -1)
				return (-1);
			count += check;
			continue ;
		}
		count++;
		ft_putchar_fd(format[i], fd);
	}
	va_end(args);
	return (count);
}
