/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:00:09 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/15 11:03:40 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	flen;
	size_t	tlen;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	flen = ft_strlen(s1);
	tlen = ft_strlen(s2) + flen;
	ptr = malloc(tlen + 1 * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s1, flen + 1);
	ft_strlcat(ptr, s2, tlen + 1);
	return (ptr);
}
