/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:34:22 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/12/27 12:36:25 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Structure

typedef struct s_struct
{
	char	*line;
	char	*buffer;
	int		fd;
	ssize_t	rd;
	char	*remain[4096];
}			t_struct;

// Main Function
char	*get_next_line(int fd);

// Utils
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2, int size);
char	*gnl_strdup(char *s, int start);
char	*gnl_truncate(char *str, int from);
void	gnl_str_cleaner(t_struct *data, int remain_bool, \
						int line_bool, int buffer_bool);

#endif // GET_NEXT_LINE_H
