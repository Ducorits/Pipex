/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 15:19:13 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 12:49:26 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be
 * part of the string; therefore if c is `\0',
 * the function locates the terminating `\0'.
 *
 * @param s The string to look through.
 * @param c The character to locate.
 * @return Pointer to the located character,
 * or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) s + i);
	return (NULL);
}
