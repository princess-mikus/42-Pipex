/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:06:41 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:18:17 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	unsigned int	div;
	unsigned int	len;
	char			current;
	int				i;

	div = 1;
	len = 1;
	i = 0;
	while (n / div > 9)
	{
		div *= 10;
		len++;
	}
	while (len-- >= 1)
	{
		current = (n / div) + 48;
		if (write(fd, &current, 1) == -1)
			return (-1);
		n = n % div;
		div /= 10;
		i++;
	}
	return (i);
}
