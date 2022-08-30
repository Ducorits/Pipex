/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 12:04:29 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 15:35:02 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 *
 * @param dst The memory to copy to.
 * @param src The string to copy.
 * @param dstsize The size of the dst memory.
 * @return The total length of the string to be created.
 * (This may differ from the size of the string actually created)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
