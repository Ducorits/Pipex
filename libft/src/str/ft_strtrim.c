/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 19:41:04 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 14:02:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char *str)
{
	while (c != *str && *str != '\0')
	{
		str++;
	}
	if (c == *str)
		return (1);
	return (0);
}

/**
 * @brief Allocates and returns a copy of ’s1’ with the characters specified
 * in ’set’ removed from the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param s2 The reference set of characters to trim.
 * @return The trimmed string.
 * NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	strlen;
	size_t	i;
	char	*trimmed_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	strlen = ft_strlen(s1);
	while (in_set(s1[i], (char *)s2) && i < strlen)
		i++;
	while (in_set(s1[strlen], (char *)s2) && strlen > i)
		strlen--;
	trimmed_str = ft_substr(s1, i, strlen - i + 1);
	return (trimmed_str);
}
