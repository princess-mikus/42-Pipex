/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:33:23 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/12/27 12:35:32 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_revcompare(char const *s1, char const *set, int len, int i)
{
	int	j;

	j = 0;
	while (len - 1 >= i)
	{
		while (s1[len - 1] != set[j] && set[j])
			j++;
		if (!set[j])
			return (len);
		else
			len--;
		j = 0;
	}
	return (len);
}

static int	ft_compare(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i] != set[j] && set[j])
			j++;
		if (!set[j])
			return (i);
		else
			i++;
		j = 0;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;
	int		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = ft_compare(s1, set);
	j = ft_revcompare(s1, set, len, i);
	ptr = malloc(((j - i) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	k = 0;
	while (i < j && s1[i])
		ptr[k++] = s1[i++];
	ptr[k] = '\0';
	return (ptr);
}
