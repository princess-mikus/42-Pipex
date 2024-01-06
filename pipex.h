/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:57:17 by mikus             #+#    #+#             */
/*   Updated: 2024/01/04 22:12:12 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void	free_array(void **array);
int		manage_here_doc(char *delimiter);