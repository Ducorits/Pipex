/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 19:04:49 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:03:47 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c
 * (converted to an unsigned char) in string s.
 *
 * @param s The string to search through.
 * @param c The character to look for.
 * @param n The amount of bytes to check.
 * @return Pointer to the byte located,
 * or NULL if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n > 0)
	{
		if (*src == (unsigned char)c)
		{
			return ((void *)src);
		}
		src++;
		n--;
	}
	return (NULL);
}
