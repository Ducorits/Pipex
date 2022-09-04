/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/04 16:21:16 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

char	*check_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*suffix;

	i = 0;
	// cmd_path = malloc(1);
	// cmd_path[0] = 0;
	suffix = ft_strjoin("/", cmd);
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], suffix);
		if (!access(cmd_path, X_OK))
		{
			free(suffix);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(suffix);
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

// void	pipex(int fd1, int fd2)
// {
// 	int		end[2];
// 	pid_t	parent;

// 	pipe(end);
// 	parent = fork();
// 	if (parent < 0)
// 		return (perror("Fork: "));
// 	if (!parent)
// 		ft_printf("child\n");
// 	else
// 		ft_printf("parent\n");
// }

int	main(int argc, char **argv, char **envp)
{
	int		len;
	pid_t	id;
	char	**paths;
	char	*bin_path;
	// char * const	args[] = {NULL};

	bin_path = 0;
	paths = get_paths(envp);
	bin_path = check_paths(paths, argv[1]);
	if (argc > 1)
	{
		len = ft_strlen(argv[1]);
		write(1, argv[1], len);
		write(1, "\n", 1);
		if (!bin_path)
		{
			ft_printf("No executable found.\n");
			return (0);
		}
		id = fork();
		if (id == 0)
		{
			ft_printf("I am child\n");
			execve(bin_path, &argv[1], envp);
		}
	}
	return (0);
}
