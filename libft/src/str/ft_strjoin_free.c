/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_free.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 16:07:27 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/20 16:17:09 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * Frees 's1' before returning.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (str)
	{
		ft_memcpy(str, s1, s1len);
		ft_memcpy(&str[s1len], s2, s2len + 1);
	}
	free(s1);
	return (str);
}
