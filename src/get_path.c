/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 09:24:54 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/17 09:41:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

char	**get_env_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			paths = ft_split(&envp[i][5], ':');
		i++;
	}
	return (paths);
}

char	*check_env_paths(char **envp, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*suffix;
	char	**paths;

	i = 0;
	cmd_path = NULL;
	paths = get_env_paths(envp);
	suffix = ft_strjoin("/", cmd);
	if (ft_strncmp("./", cmd, 2) && ft_strncmp("/", cmd, 1) && paths && suffix)
	{
		while (paths[i])
		{
			cmd_path = ft_strjoin(paths[i], suffix);
			if (!access(cmd_path, X_OK))
				break ;
			free(cmd_path);
			cmd_path = NULL;
			i++;
		}
	}
	free(suffix);
	free_pointer_array(paths);
	return (cmd_path);
}

char	*get_cmd_path(char **argv, char **envp, char *cmd)
{
	char	*cmd_path;

	if (!cmd)
		return (0);
	cmd_path = check_env_paths(envp, cmd);
	if (cmd_path)
	{
		if (is_dir(argv, cmd_path))
			return (free(cmd_path), NULL);
		return (cmd_path);
	}
	if (!access(cmd, X_OK))
	{
		if (is_dir(argv, cmd))
			return (free(cmd_path), NULL);
		return (cmd);
	}
	return (NULL);
}
