/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:44:11 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:56 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printargs(va_list *args, char c)
{
	if (c == 'c')
		return (ft_print_c(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_p(va_arg(*args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_print_u(va_arg(*args, unsigned int)));
	else if (c == 'X' || c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), c));
	else if (c == '%')
		return (ft_print_c('%'));
	return (-1);
}
