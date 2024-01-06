/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:45:05 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:45:13 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*orig;

	dest = (char *)dst;
	orig = (char *)src;
	if (dest > orig)
		while (len--)
			dest[len] = orig[len];
	else if (dest < orig)
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
