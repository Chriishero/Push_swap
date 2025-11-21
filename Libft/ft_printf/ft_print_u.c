/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:59:58 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:55 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_u(unsigned int u)
{
	char	*nbr;
	int		nbr_len;

	u += UINT_MAX + 1;
	nbr = ft_ltoa(u);
	ft_putstr_fd(nbr, 1);
	nbr_len = ft_strlen(nbr);
	free(nbr);
	return (nbr_len);
}
