/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:48:27 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/15 23:53:00 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_int(int n, int fd)
{
	char	*nbr;
	int		nbr_len;

	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, fd);
	nbr_len = ft_strlen(nbr);
	free(nbr);
	return (nbr_len);
}
