/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/31 14:10:04 by dritsema      #+#    #+#                 */
/*   Updated: 2022/01/12 12:42:11 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	check_newline(t_return *buf)
{
	int	count;

	count = 0;
	if (buf->content)
	{
		while (count < buf->size)
		{
			if (buf->content[count] == '\n' || buf->content[count] == '\0')
				return (count + 1);
			count++;
		}
	}
	return (0);
}

int	newline_pos(t_buf read)
{
	int	i;

	i = 0;
	while (i < read.size)
	{
		if (read.content[i] == '\n' || read.content[i] == '\0')
		{
			return (i + 1);
		}
		i++;
	}
	return (i);
}

void	past_newline(t_buf *read)
{
	int	i;
	int	j;

	i = newline_pos(*read);
	j = 0;
	while (j < read->size - i)
	{
		read->content[j] = read->content[i + j];
		j++;
	}
	read->size = j;
}

char	*add_to_str(t_buf read, t_return *buf)
{
	int		i;
	int		j;
	char	*str;

	i = newline_pos(read);
	str = malloc(sizeof(char) * buf->size + i + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	while (j < buf->size)
	{
		str[j] = buf->content[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		str[buf->size + j] = read.content[j];
		j++;
	}
	str[buf->size + i] = '\0';
	if (buf->size)
		free(buf->content);
	buf->size = buf->size + i;
	return (str);
}
