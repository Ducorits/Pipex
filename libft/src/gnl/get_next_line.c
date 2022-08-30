/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/31 14:09:08 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:55:21 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/**
 * @brief Returns a line read from a
 * file descriptor.
 *
 * @param fd File descriptor to read from.
 * @return Newly allocated string containing the next line.
 */
char	*get_next_line(int fd)
{
	static t_buf	r_buf;
	t_return		buf;

	buf.size = 0;
	while (!check_newline(&buf))
	{
		if (r_buf.size > 0)
		{
			buf.content = add_to_str(r_buf, &buf);
			if (buf.content == NULL)
				return (NULL);
			past_newline(&r_buf);
		}
		else
		{
			r_buf.size = read(fd, r_buf.content, BUFFER_SIZE);
			if (r_buf.size < 1)
				break ;
		}
	}
	if (buf.size != 0)
	{
		return (buf.content);
	}
	return (0);
}
