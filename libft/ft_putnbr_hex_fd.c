/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:32:21 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:17:21 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd(unsigned int n, int fd, int mayus)
{
	unsigned int		div;
	unsigned int		len;
	int					i;
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
		else if (mayus == 1)
			current = (n / div) - 10 + 65;
		else
			current = (n / div) - 10 + 97;
		if (write(fd, &current, 1) == -1)
			return (-1);
		n = n % div;
		div /= 16;
		i++;
	}
	return (i);
}
