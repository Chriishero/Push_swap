/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:48:27 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 06:45:53 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_int(int n)
{
	char	*nbr;
	int		nbr_len;

	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	nbr_len = ft_strlen(nbr);
	free(nbr);
	return (nbr_len);
}
