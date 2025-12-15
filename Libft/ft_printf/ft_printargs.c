/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:44:11 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:54:21 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printargs(va_list *args, char c, int fd)
{
	if (c == 'c')
		return (ft_print_c(va_arg(*args, int), fd));
	else if (c == 's')
		return (ft_print_s(va_arg(*args, char *), fd));
	else if (c == 'p')
		return (ft_print_p(va_arg(*args, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*args, int), fd));
	else if (c == 'u')
		return (ft_print_u(va_arg(*args, unsigned int), fd));
	else if (c == 'X' || c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), c, fd));
	else if (c == '%')
		return (ft_print_c('%', fd));
	return (-1);
}
