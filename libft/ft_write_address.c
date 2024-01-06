/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:23:17 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:44:09 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_address(va_list lst)
{
	void	*ptr;
	int		count;
	int		errors;

	ptr = va_arg(lst, void *);
	count = (int)write(1, "0x", 2);
	if (count == -1)
		return (-1);
	errors = ft_putaddress_fd((unsigned long)ptr, 1);
	if (errors == -1)
		return (-1);
	return (errors + count);
}
