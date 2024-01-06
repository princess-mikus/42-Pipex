/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:31 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:38:44 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress_fd(unsigned long n, int fd)
{
	unsigned long		div;
	int					len;
	int					i;
	int					errors;
	char				current;

	div = 1;
	len = 0;
	i = 0;
	while (len++ >= 0 && n / div >= 16)
		div *= 16;
	while (len-- >= 1)
	{
		if (n / div <= 9)
			current = (n / div) + 48;
		else
			current = (n / div) - 10 + 97;
		errors = write(fd, &current, 1);
		if (errors == -1)
			return (-1);
		n = n % div;
		div /= 16;
		i++;
	}
	return (i);
}
