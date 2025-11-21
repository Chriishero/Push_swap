/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvillene <cvillene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:34:13 by cvillene          #+#    #+#             */
/*   Updated: 2025/11/21 08:59:57 by cvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define CHECK_ARGS_H
# define TRUE 1
# define FALSE -1
# define SUCCESS TRUE
# define FAILURE FALSE
# include "Libft/libft.h"
# include "utils.h"

void	check_args(int argc, char **argv);
void	error(void);
int		check_modes(int argc, char **argv);
int		check_list(char *list);

#endif