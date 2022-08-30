/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 12:39:36 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 14:00:01 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered
 * to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 *
 * @param s The string to search through.
 * @param c The character to find.
 * @return Pointer to the located character,
 * or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*b;

	i = 0;
	b = (char *) s + i;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			b = (char *) s + i;
		i++;
	}
	if (s[i] == c)
		b = (char *) s + i;
	if (*b == (char) c)
		return ((char *) b);
	else
		return (NULL);
}
