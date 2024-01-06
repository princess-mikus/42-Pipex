/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:54:41 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:55:36 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	if ((unsigned char)c == '\0')
		return (((char *)s) + ft_strlen(s));
	else if (c != '\0')
		while (s[++i])
			if (s[i] == (unsigned char)c && s[i] != '\0')
				return (((char *)s) + i);
	return (NULL);
}
