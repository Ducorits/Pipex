/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/05 14:15:28 by dritsema      ########   odam.nl         */
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

int	free_pointer_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
	{
		i++;
	}
	paths = ft_split(envp[i], ':');
	if (paths)
		ft_strlcpy(&paths[0][0], &paths[0][5], ft_strlen(paths[0]));
	return (paths);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*suffix;
	char	**paths;

	i = 0;
	paths = get_paths(envp);
	suffix = ft_strjoin("/", cmd);
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], suffix);
		if (!access(cmd_path, X_OK))
		{
			free(suffix);
			free_pointer_array(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_pointer_array(paths);
	free(suffix);
	return (0);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	if (pid == 0)
	{
		first_process(fd1, end, argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		last_process(fd2, end, argv, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];

	if (argc == 5)
	{
		fds[0] = open(argv[1], O_RDONLY);
		fds[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		if (fds[0] == -1)
		{
			ft_printf("%s: %s: %s\n", argv[0], argv[1], strerror(errno));
			return (1);
		}
		pipex(fds[0], fds[1], argv, envp);
	}
	else
		ft_printf("%s: Incorrect argument count\n", argv[0]);
	return (0);
}
