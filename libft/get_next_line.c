/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:37:39 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/12/27 13:08:53 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_last_remain(t_struct *data, int i)
{
	free(data->buffer);
	data->buffer = NULL;
	data->line = NULL;
	if (data->rd == -1)
	{
		free(data->remain[data->fd]);
		data->remain[data->fd] = NULL;
		return ;
	}
	while (data->remain[data->fd][i] != '\n' && data->remain[data->fd][i])
		i++;
	data->line = gnl_strjoin(data->line, data->remain[data->fd], i);
	if (data->remain[data->fd][i] == '\n')
	{
		if (data->remain[data->fd][i + 1])
		{
			data->remain[data->fd] = \
			gnl_truncate(data->remain[data->fd], i + 1);
			return ;
		}
	}
	free(data->remain[data->fd]);
	data->remain[data->fd] = NULL;
}

int	ft_remain_copy(t_struct *data)
{
	if (data->remain[data->fd])
	{
		data->line = gnl_strdup(data->remain[data->fd], 0);
		if (!data->line)
			return (gnl_str_cleaner(data, 1, 1, 1), 0);
		data->remain[data->fd] = NULL;
	}
	else if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	return (1);
}

void	line_reader(t_struct *data, int i)
{
	while (data->rd > 0)
	{
		i = 0;
		while (data->buffer[i] != '\n' && data->buffer[i] != '\0')
			i++;
		data->line = gnl_strjoin(data->line, data->buffer, i);
		if (!data->line)
			return (gnl_str_cleaner(data, 1, 1, 1));
		if (data->buffer[i] == '\n')
		{
			if (data->buffer[i + 1])
			{
				data->remain[data->fd] = gnl_strdup(data->buffer, i + 1);
				if (!data->remain[data->fd])
					return (gnl_str_cleaner(data, 1, 1, 1));
			}
			else
				gnl_str_cleaner(data, 1, 0, 1);
			return ;
		}
		data->rd = (int)read(data->fd, data->buffer, BUFFER_SIZE);
		data->buffer[data->rd] = '\0';
	}
	gnl_str_cleaner(data, 1, 0, 1);
}

int	remain_new_line_search(t_struct *data, int fd)
{
	int	i;

	i = 0;
	if (data->rd == -1)
		return (gnl_str_cleaner(data, 1, 1, 1), 0);
	if (data->fd < 0 || data->fd != fd || !data->remain[data->fd])
		return (0);
	while (data->remain[data->fd][i] && data->remain[data->fd][i] != '\n')
		i++;
	if (!data->remain[data->fd][i])
		return (0);
	data->line = gnl_strjoin(data->line, data->remain[data->fd], i);
	if (data->remain[data->fd][i + 1])
		data->remain[data->fd] = gnl_truncate(data->remain[data->fd], i + 1);
	else
	{
		free(data->remain[data->fd]);
		data->remain[data->fd] = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_struct	data = {NULL, NULL, -1, 1, {NULL, NULL}};

	if (fd < 0)
		return (NULL);
	data.line = NULL;
	if (remain_new_line_search(&data, fd), data.line)
		return (data.line);
	data.fd = fd;
	data.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!data.buffer)
		return (gnl_str_cleaner(&data, 1, 1, 1), NULL);
	data.rd = read(data.fd, data.buffer, BUFFER_SIZE);
	if (data.rd < 0 || (data.rd == 0 && !data.remain[data.fd]))
		return (gnl_str_cleaner(&data, 0, 0, 1), NULL);
	data.buffer[data.rd] = '\0';
	if (data.rd > 0)
	{
		if (!ft_remain_copy(&data))
			return (NULL);
		return (line_reader(&data, 0), data.line);
	}
	else if (data.remain[data.fd] && data.rd == 0)
		return (manage_last_remain(&data, 0), data.line);
	return (NULL);
}
