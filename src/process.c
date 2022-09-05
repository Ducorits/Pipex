/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:31:24 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/05 12:52:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>

void	first_process(int fd, int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;

	args = ft_split(argv[2], ' ');
	bin_path = get_path(envp, args[0]);
	if (bin_path)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		// ft_printf("%s\n", bin_path);
		// free(bin_path);
		close(pipe[1]);
		close(pipe[0]);
		close(fd);
		execve(bin_path, args, envp);
	}
	else
	{
		ft_printf("Command '%s' not found.\n", args[0]);
		free_pointer_array(args);
		free(bin_path);
	}
}

void	last_process(int fd, int *pipe, char **argv, char **envp)
{
	char	*bin_path;
	char	**args;

	args = ft_split(argv[3], ' ');
	bin_path = get_path(envp, args[0]);
	if (bin_path && args)
	{
		dup2(fd, STDOUT_FILENO);
		dup2(pipe[0], STDIN_FILENO);
		close(pipe[1]);
		close(pipe[0]);
		close(fd);
		execve(bin_path, args, envp);
	}
	else
	{
		ft_printf("Command '%s' not found.\n", args[0]);
		free_pointer_array(args);
		free(bin_path);
	}
}
