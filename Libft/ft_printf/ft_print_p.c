/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:12:04 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:54 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_p(unsigned long p)
{
	char	*address;
	char	*hex;
	int		address_len;

	address = NULL;
	hex = ft_dectohex_unsigned(p, 1);
	if (p == 0)
		address = "(nil)";
	else
		address = ft_strjoin("0x", hex);
	ft_putstr_fd(address, 1);
	address_len = ft_strlen(address);
	if (p != 0)
		free(address);
	free(hex);
	return (address_len);
}
