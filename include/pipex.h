/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:30:16 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/05 12:44:55 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

void	first_process(int fd, int *pipe, char **argv, char **envp);
void	last_process(int fd, int *pipe, char **argv, char **envp);
char	*get_path(char **envp, char *cmd);
int		free_pointer_array(char **array);

#endif // PIPEX_H
