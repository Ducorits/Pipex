/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:45:58 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/16 13:45:49 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_printstr(char *s)
{
	int	slen;

	if (!s)
		return (write(1, "(null)", 6));
	slen = ft_strlen(s);
	return (write(1, s, slen));
}
