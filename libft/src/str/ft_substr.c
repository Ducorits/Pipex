/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 16:25:41 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 14:02:26 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 *
 * @param s The string to make a substring from.
 * @param start The starting index in string 's'.
 * @param len The maximum length of the substring to return.
 * @return The newly created substring of 's'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	malloc_size;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	else if (slen >= (len + (start + 1)))
		malloc_size = len + 1;
	else
		malloc_size = slen - start + 1;
	sub = (char *)malloc(malloc_size * sizeof(char));
	if (sub)
	{
		ft_memcpy(sub, (s + start), malloc_size);
		sub[malloc_size - 1] = '\0';
	}
	return (sub);
}
