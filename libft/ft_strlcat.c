/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:53:20 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:53:30 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = -1;
	if (dstsize == 0 && (!dst || !src))
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (ft_strlen(src) + dstsize);
	while (++i < (dstsize - dlen - 1) && src[i])
		dst[dlen + i] = src[i];
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
