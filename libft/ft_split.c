/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:10 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:36 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ptr, int k)
{
	while (k--)
		free(ptr[k]);
	free(ptr);
	return (NULL);
}

static int	ft_get_total_words(char const *s, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	if (s[i] == '\0')
		return (0);
	if (c == '\0')
		index--;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			index++;
		i++;
	}
	if (s[i - 1] == c)
		index--;
	return (index);
}

static int	ft_init_j(const char *s, char c, int j, int i)
{
	j = i;
	while (s[j])
	{
		if (s[j] != c)
			return (j);
		j++;
	}
	return (j);
}

static int	ft_init_i(const char *s, char c, int i, int j)
{
	i = j;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		index;
	char	**str;

	if (s != NULL)
		str = malloc((ft_get_total_words(s, c) + 1) * sizeof(char *));
	if (!s || (s && !str))
		return (NULL);
	index = ft_get_total_words(s, c);
	i = 0;
	j = 0;
	k = 0;
	while (index-- > 0)
	{
		j = ft_init_j(s, c, j, i);
		i = ft_init_i(s, c, i, j);
		str[k] = ft_substr(s, j, i - j);
		if (str[k++] == NULL)
			return (ft_free(str, k));
	}
	str[k] = NULL;
	return (str);
}
