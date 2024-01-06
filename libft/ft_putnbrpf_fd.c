/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:54:53 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 12:08:12 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_negative(int *n, int fd)
{
	if (*n < 0)
	{
		*n *= -1;
		return (write(fd, "-", 1));
	}
	return (0);
}

int	ft_putnbrpf_fd(int n, int fd)
{
	int		div;
	int		len;
	int		ret;
	char	current;

	div = 1;
	len = -1;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	ret = ft_check_negative(&n, fd);
	if (ret == -1)
		return (-1);
	while (++len >= 0 && n / div > 9)
		div *= 10;
	ret += len + 1;
	while (len-- >= 0)
	{
		current = n / div + 48;
		if (write(fd, &current, 1) == -1)
			return (-1);
		n = n % div;
		div /= 10;
	}
	return (ret);
}
