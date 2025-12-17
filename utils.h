/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:54:49 by cvillene          #+#    #+#             */
/*   Updated: 2025/12/17 23:26:39 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILURE -1
# include "Libft/libft.h"
# include "stack.h"

void	free_after_split(char **tab);
int		stack_size(t_stack *s);
// ceil_sqrt round the numbers up
// ex : ceil_sqrt(90) = 10, but floor_sqrt(90) = 9 and sqrt(90) ≈ 9.48683298
int		ft_ceil_sqrt(int n);
long	ft_atol(const char *nptr);
char	*toupper_first_letter(char *str);
int		are_strs_equals(char *str1, char *str2);
#endif