/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:50 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/10/19 11:40:01 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_str_cleaner(t_struct *data, int remain_bool, \
						int line_bool, int buffer_bool)
{
	if (remain_bool == 1)
	{
		if (data->remain[data->fd])
			free(data->remain[data->fd]);
		data->remain[data->fd] = NULL;
	}
	if (line_bool == 1)
	{
		if (data->line)
			free(data->line);
		data->line = NULL;
	}
	if (buffer_bool == 1)
	{
		if (data->buffer)
			free(data->buffer);
		data->buffer = NULL;
	}
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, int size)
{
	char	*ptr;
	int		flen;
	int		tlen;
	int		i;
	int		j;

	flen = (int)gnl_strlen(s1);
	tlen = (int)gnl_strlen(s2);
	if (tlen > size)
		tlen = size + 1;
	ptr = malloc((tlen + flen + 1) * sizeof(char));
	if (ptr == NULL)
		return (free(s1), ptr);
	i = -1;
	while (++i <= flen && s1 && s1[i])
		ptr[i] = s1[i];
	j = 0;
	while (i < flen + tlen && s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

char	*gnl_strdup(char *s, int start)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	len = (int)gnl_strlen(s);
	if (!s)
	{
		s2 = malloc(sizeof(char));
		s2[0] = '\0';
		return (s2);
	}
	i = start;
	s2 = malloc((len - start + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	j = 0;
	while (i <= len && s[i])
		s2[j++] = s[i++];
	s2[j] = '\0';
	free(s);
	return (s2);
}

char	*gnl_truncate(char *str, int from)
{
	char	*ptr;
	int		i;
	int		j;

	i = from;
	j = 0;
	ptr = malloc((gnl_strlen(str) - from + 1) * sizeof(char));
	if (ptr == NULL)
		return (free(str), NULL);
	while (str[i])
		ptr[j++] = str[i++];
	ptr[j] = '\0';
	free(str);
	return (ptr);
}
