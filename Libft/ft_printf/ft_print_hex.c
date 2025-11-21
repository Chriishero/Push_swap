/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:25:03 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:53 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_hex(unsigned int x, char c)
{
	char	*hex;
	int		hex_len;

	x += UINT_MAX + 1;
	hex = NULL;
	if (c == 'x')
		hex = ft_dectohex_signed(x, 1);
	else if (c == 'X')
		hex = ft_dectohex_signed(x, 0);
	ft_putstr_fd(hex, 1);
	hex_len = ft_strlen(hex);
	free(hex);
	return (hex_len);
}
