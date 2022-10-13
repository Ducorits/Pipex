/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:30:16 by dritsema      #+#    #+#                 */
/*   Updated: 2022/10/13 16:38:56 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

int		is_dir(char **argv, char *path);
char	*get_path(char **argv, char **envp, char *cmd);
void	free_pointer_array(char **array);
void	write_error(char *str1, char *str2, char *str3);
bool	redir(int *fd, char *path, t_redir_type type);

typedef enum s_redir_type
{
	INFILE,
	OUTFILE,
	END
}	t_redir_type;

#endif // PIPEX_H
