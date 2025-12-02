/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:54:49 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/02 07:05:26 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define TRUE 1
# define FALSE -1
# define SUCCESS 1
# define FAILURE -1
# include "Libft/libft.h"
# include "stack.h"

void	free_after_split(char **tab);
int		stack_size(t_stack *s);

#endif