/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mikus <Kiankocasaubon01@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:19:06 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/11 15:50:21 by Mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

static char	*ft_edge_cases(int n)
{
	char	*arr;

	if (n == -2147483648)
	{
		arr = malloc (12 * sizeof(char));
		if (arr == NULL)
			return (NULL);
		ft_strlcpy(arr, "-2147483648", 12);
	}
	if (n == 2147483647)
	{
		arr = malloc (11 * sizeof(char));
		if (arr == NULL)
			return (NULL);
		ft_strlcpy(arr, "2147483647", 11);
	}
	if (n == 0)
	{
		arr = malloc (2 * sizeof(char));
		if (arr == NULL)
			return (NULL);
		arr[0] = '0';
		arr[1] = '\0';
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	unsigned int	div;
	int				len;
	int				neg;
	char			*arr;

	div = 1;
	neg = ft_isnegative(&n);
	len = neg;
	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (ft_edge_cases(n));
	while ((n / div > 0) && ++len > 0)
		div *= 10;
	arr = malloc((++len) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[--len] = '\0';
	while (--len >= (0 + neg))
	{
		arr[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg == 1)
		arr[0] = '-';
	return (arr);
}
