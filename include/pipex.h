/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:30:16 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/17 12:32:25 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>

typedef enum s_redir_type
{
	INFILE,
	OUTFILE,
	PIPEIN,
	PIPEOUT,
	END
}	t_redir_type;

int		is_dir(char **argv, char *path);
char	*get_cmd_path(char **argv, char **envp, char *cmd);
void	free_pointer_array(char **array);
void	write_error(char *str1, char *str2, char *str3);
bool	redir(int *fd, char *path, t_redir_type type);
void	close_pipes(int *pipe_fds);

#endif // PIPEX_H
