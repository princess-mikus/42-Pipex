/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:06:41 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 11:06:47 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	int		len;
	char	current;

	div = 1;
	len = -1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		while (++len >= 0 && n / div > 9)
			div *= 10;
		while (len-- >= 0)
		{
			current = n / div + 48;
			write(fd, &current, 1);
			n = n % div;
			div /= 10;
		}
	}
}
