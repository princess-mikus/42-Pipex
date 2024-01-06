/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:18 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:56:25 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	size_t	hlen;

	i = -1;
	if (len == 0 && (!haystack || !needle))
		return (NULL);
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen > hlen)
		return (NULL);
	if (nlen == 0)
		return ((char *)haystack);
	while (++i <= len)
		if (haystack[i] == needle[0] && len - i >= nlen && haystack[i])
			if (ft_strncmp(haystack + i, needle, nlen) == 0)
				return ((char *)haystack + i);
	return (NULL);
}
