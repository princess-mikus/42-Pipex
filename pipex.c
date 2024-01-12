/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:02:37 by mikus             #+#    #+#             */
/*   Updated: 2024/01/12 20:17:55 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *executable, char **envp)
{
	char	*arguments[3];
	char	*path;
	int		pfd[2];

	arguments[0] = "which";
	arguments[1] = executable;
	arguments[2] = NULL;
	if (pipe(pfd) == -1)
		return (NULL);
	if (!fork())
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		execve("/usr/bin/which", arguments, envp);
		exit (2);
	}
	else
		wait(NULL);
	close(pfd[1]);
	path = get_next_line(pfd[0]);
	close(pfd[0]);
	if (path)
		return (path[ft_strlen(path) - 1] = '\0', path);
	return (NULL);
}

int	fork_and_execute(char *program, int readpipe, char **envp)
{
	char	**arguments;
	char	*path;
	int		pipefd[2];
	int		status;

	arguments = ft_split(program, ' ');
	path = get_path(arguments[0], envp);
	status = 0;
	pipe(pipefd);
	if (!fork())
	{
		dup2(readpipe, STDIN_FILENO);
		close(readpipe);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve(path, arguments, envp);
		exit(2);
	}
	wait(NULL);
	status = 0;
	close(readpipe);
	close(pipefd[1]);
	if (status)
		return (free(path), free_array((void **)arguments), -1);
	return (free(path), free_array((void **)arguments), pipefd[0]);
}

int	open_infile(char *filename, char *outfile, int *outfile_fd)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	*outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (*outfile_fd == -1)
		return (close(fd), -1);
	return (fd);
}

void	write_to_outfile(int outfile_fd, int pipefd, int rd)
{
	char	contents[4096];

	rd = read(pipefd, contents, 4096);
	contents[rd] = '\0';
	ft_putstr_fd(contents, outfile_fd);
	if (rd > 0)
		write_to_outfile(outfile_fd, pipefd, rd);
	else
	{
		close(outfile_fd);
		close(pipefd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		readpipe;
	int		outfile_fd;

	if (argc != 5)
		return (perror("Wrong number of arguments"), 2);
	readpipe = open_infile(argv[1], argv[4], &outfile_fd);
	if (readpipe == -1)
		return (perror("Can't open infile"), 2);
	readpipe = fork_and_execute(argv[2], readpipe, envp);
	if (readpipe == -1)
		return (perror("Command 1 failed, not valid command"), 2);
	readpipe = fork_and_execute(argv[3], readpipe, envp);
	if (readpipe == -1)
		return (perror("Command 2 failed, not valid command"), 2);
	write_to_outfile(outfile_fd, readpipe, 0);
	return (0);
}
