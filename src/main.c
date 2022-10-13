/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/11 11:22:34 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

int	is_dir(char **argv, char *path)
{
	int	fd;

	fd = open(path, O_WRONLY);
	if (fd == -1 && errno == EISDIR)
	{
		write_error(argv[0], path, strerror(errno));
		return (1);
	}
	close(fd);
	return (0);
}

void	first_process(int fd, int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;

	args = ft_split(argv[2], ' ');
	bin_path = 0;
	if (args)
		bin_path = get_path(argv, envp, args[0]);
	if (bin_path && args)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		close(pipe[1]);
		close(pipe[0]);
		close(fd);
		if (execve(bin_path, args, envp) < 0)
			write_error(argv[0], strerror(errno), args[0]);
	}
	else
	{
		if (errno != EISDIR)
			write_error(argv[0], "command not found", args[0]);
	}
	free_pointer_array(args);
	free(bin_path);
	exit(127);
}

void	last_process(int fd, int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;

	args = ft_split(argv[3], ' ');
	bin_path = 0;
	if (args)
		bin_path = get_path(argv, envp, args[0]);
	if (bin_path && args)
	{
		dup2(fd, STDOUT_FILENO);
		dup2(pipe[0], STDIN_FILENO);
		close(pipe[1]);
		close(pipe[0]);
		close(fd);
		if (execve(bin_path, args, envp) < 0)
			write_error(argv[0], strerror(errno), args[0]);
	}
	else
	{
		if (errno != EISDIR)
			write_error(argv[0], "command not found", args[0]);
	}
	free_pointer_array(args);
	free(bin_path);
	exit(127);
}

int	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	int		status;
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "), 1);
	if (pid == 0)
		first_process(fd1, end, argv, envp);
	else
	{
		pid = fork();
		if (pid == 0)
			last_process(fd2, end, argv, envp);
	}
	close(end[0]);
	close(end[1]);
	waitpid(pid, &status, WUNTRACED);
	wait(NULL);
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	int		exit_status;

	if (argc == 5)
	{
		fds[0] = open(argv[1], O_RDONLY); // open files in fork
		if (fds[0] == -1)
			write_error(argv[0], argv[1], strerror(errno));
		fds[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (fds[1] == -1)
			write_error(argv[0], argv[4], strerror(errno));
		if (fds[0] == -1 || fds[1] == -1)
			return (1);
		exit_status = pipex(fds[0], fds[1], argv, envp);
		close(fds[0]);
		close(fds[1]);
		return (exit_status);
	}
	else
	{
		write(STDERR_FILENO, argv[0], ft_strlen(argv[0]));
		write(STDERR_FILENO, ": Incorrect argument count.\n", 28);
	}
	return (1);
}
