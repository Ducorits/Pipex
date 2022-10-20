/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/20 11:45:28 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

void	first_process(int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;
	int		fd;

	args = ft_split(argv[2], ' ');
	bin_path = NULL;
	if (args && redir(&fd, argv[1], INFILE)
		&& redir(&pipe[1], NULL, PIPEOUT))
	{
		close_pipes(pipe);
		close(fd);
		bin_path = get_cmd_path(argv, envp, args[0]);
		if (bin_path == NULL)
			write_error(argv[0], "command not found", args[0]);
		if (bin_path && execve(bin_path, args, envp) < 0)
			write_error(argv[0], strerror(errno), args[0]);
	}
	close_pipes(pipe);
	free_pointer_array(args);
	free(bin_path);
	exit(127);
}

void	last_process(int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;
	int		fd;

	args = ft_split(argv[3], ' ');
	bin_path = NULL;
	if (args && redir(&fd, argv[4], OUTFILE)
		&& redir(&pipe[0], NULL, PIPEIN))
	{
		close_pipes(pipe);
		close(fd);
		bin_path = get_cmd_path(argv, envp, args[0]);
		if (bin_path == NULL)
			write_error(argv[0], "command not found", args[0]);
		if (bin_path && execve(bin_path, args, envp) < 0)
			write_error(argv[0], strerror(errno), args[0]);
	}
	close_pipes(pipe);
	free_pointer_array(args);
	free(bin_path);
	exit(127);
}

int	pipex(char **argv, char **envp)
{
	int		pipe_fds[2];
	int		status;
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
		return (write_error(argv[0], "pipe", strerror(errno)), errno);
	pid = fork();
	if (pid < 0)
		return (write_error(argv[0], "fork", strerror(errno)), errno);
	if (pid == 0)
		first_process(pipe_fds, argv, envp);
	else
	{
		pid = fork();
		if (pid < 0)
			return (write_error(argv[0], "fork", strerror(errno)), errno);
		if (pid == 0)
			last_process(pipe_fds, argv, envp);
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(pid, &status, WUNTRACED);
	wait(NULL);
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		exit_status;

	if (argc == 5)
	{
		exit_status = pipex(argv, envp);
		return (exit_status);
	}
	else
	{
		write(STDERR_FILENO, argv[0], ft_strlen(argv[0]));
		write(STDERR_FILENO, ": Incorrect argument count.\n", 28);
	}
	return (1);
}
