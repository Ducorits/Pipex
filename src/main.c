/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/05 12:51:36 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

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
			// ft_printf("%s\n", cmd_path);
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
		// ft_printf("child\n");
		first_process(fd1, end, argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		// ft_printf("parent, %i\n", fd2);
		last_process(fd2, end, argv, envp);
	}
	// close(end[0]);
	// close(end[1]);
}

int	main(int argc, char **argv, char **envp)
{
	// int		len;
	int		fds[2];
	// char * const	args[] = {NULL};

	fds[0] = open("./infile", O_RDONLY);
	fds[1] = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (argc > 4)
	{
		// len = ft_strlen(argv[1]);
		// write(1, argv[1], len);
		// write(1, "\n", 1);
		pipex(fds[0], fds[1], argv, envp);
	}
	close(fds[0]);
	close(fds[1]);
	return (0);
}
