/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:46:24 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:36:59 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_character(va_list lst)
{
	char	last;
	int		count;

	last = (char)va_arg(lst, int);
	count = write(1, &last, 1);
	return (count);
}
