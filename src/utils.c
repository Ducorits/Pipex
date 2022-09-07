/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:31:24 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/07 20:45:32 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	write_error(char *str1, char *str2, char *str3)
{
	int		len;
	char	*error;

	if (!str3)
		len = ft_strlen(str1) + ft_strlen(str2) + 2;
	else
		len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 2;
	error = malloc(sizeof(char) * len);
	if (!error)
	{
		write(2, "Error message allocation failed\n", 33);
		return ;
	}
	ft_strlcpy(error, str1, len);
	ft_strlcat(error, str2, len);
	if (str3)
		ft_strlcat(error, str3, len);
	ft_strlcat(error, "\n", len);
	write(STDERR_FILENO, error, len);
	free(error);
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

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i], ':');
			if (paths)
				ft_strlcpy(&paths[0][0], &paths[0][5], ft_strlen(paths[0]));
			break ;
		}
		i++;
	}
	return (paths);
}

char	*check_paths(char **envp, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*suffix;
	char	**paths;

	i = 0;
	cmd_path = 0;
	paths = get_paths(envp);
	suffix = ft_strjoin("/", cmd);
	if (ft_strncmp("./", cmd, 2) && ft_strncmp("/", cmd, 1) && paths && suffix)
	{
		while (paths[i])
		{
			cmd_path = ft_strjoin(paths[i], suffix);
			if (!access(cmd_path, X_OK))
				break ;
			free(cmd_path);
			cmd_path = 0;
			i++;
		}
	}
	free(suffix);
	free_pointer_array(paths);
	return (cmd_path);
}

char	*get_path(char **envp, char *cmd)
{
	char	*cmd_path;

	if (!cmd)
		return (0);
	cmd_path = check_paths(envp, cmd);
	if (cmd_path)
		return (cmd_path);
	if (!access(cmd, X_OK))
		return (cmd);
	return (0);
}
