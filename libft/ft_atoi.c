/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:11:44 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/15 11:37:54 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] <= '\0' && str[i] >= '\10') || str[i] == ' ' || \
	str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	neg = 1;
	i = ft_start(str);
	num = 0;
	if (str[i++] == '-')
		neg *= -1;
	else
		i--;
	while (str[i])
	{
		if ((str[i] > 32 && str[i] < 48) || (unsigned char)str[i] > 57)
			return (num * neg);
		else if (str[i] <= 32)
		{
			i++;
			break ;
		}
		num += (str[i] - 48);
		if (str[++i] >= 48 && str[i] <= 57)
			num = num * 10;
	}
	return (num * neg);
}
