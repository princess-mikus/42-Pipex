/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:54:41 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:55:34 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return (((char *)s) + i);
	else if (c != '\0')
		while (i-- && s[i])
			if (s[i] == (unsigned char)c && s[i] != '\0')
				return (((char *)s) + i);
	return (NULL);
}
