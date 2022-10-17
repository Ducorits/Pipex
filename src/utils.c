/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:31:24 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/17 12:50:10 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
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

void	write_error(char *str1, char *str2, char *str3)
{
	int		len;
	char	*error;

	if (!str3)
		len = ft_strlen(str1) + ft_strlen(str2) + 6;
	else
		len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 6;
	error = malloc(sizeof(char) * len);
	if (!error)
	{
		write(STDERR_FILENO, "Error message allocation failed\n", 33);
		return ;
	}
	ft_strlcpy(error, str1, len);
	ft_strlcat(error, ": ", len);
	ft_strlcat(error, str2, len);
	ft_strlcat(error, ": ", len);
	if (str3)
		ft_strlcat(error, str3, len);
	ft_strlcat(error, "\n", len);
	write(STDERR_FILENO, error, len);
	free(error);
}

void	close_pipes(int *pipe_fds)
{
	if (pipe_fds[0] != -1 || pipe_fds[1] != -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		pipe_fds[0] = -1;
		pipe_fds[1] = -1;
	}
}

void	free_pointer_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
