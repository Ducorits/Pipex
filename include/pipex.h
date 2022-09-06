/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:30:16 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/06 20:11:07 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

char	*get_path(char **envp, char *cmd);
void	free_pointer_array(char **array);
void	write_error(char *str1, char *str2, char *str3);

#endif // PIPEX_H
