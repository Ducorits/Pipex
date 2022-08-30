/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 12:39:39 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 13:55:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string
 * needle in the string haystack,
 * where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 *
 * @param haystack The 'haystack' to look through.
 * @param needle The 'needle' to find.
 * @param len The length to look through.
 * @return Pointer to the first occurence in haystack.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0'
			&& i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
