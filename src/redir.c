/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redir.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:28:30 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/13 16:40:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static bool	openfile(int *fd, char *path, t_redir_type type)
{
	if (type == INFILE)
		*fd = open(path, O_RDONLY);
	if (type == OUTFILE)
		*fd = open(path, O_WRONLY | O_CREAT, 0664);
	if (*fd == -1)
	{
		write_error("./pipex", path, strerror(errno));
		return (FALSE);
	}
	return (TRUE);
}

static bool	protected_dup2(int fd, t_redir_type type)
{
	int	ret;

	if (type == INFILE)
		ret = dup2(fd, STDIN_FILENO);
	if (type == OUTFILE)
		ret = dup2(fd, STDOUT_FILENO);
	if (ret == -1)
	{
		write_error("./pipex", "dup2", strerror(errno));
		return (FALSE);
	}
	return (TRUE);
}

bool	redir(int *fd, char *path, t_redir_type type)
{
	if (!openfile(fd, path, type))
		return (FALSE);
	if (!protected_dup2(*fd, type))
		return (FALSE);
	return (TRUE);
}
