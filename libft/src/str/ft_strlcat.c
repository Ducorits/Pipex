/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 14:10:43 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 15:14:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends string src to the end of dst.
 * It will append at most dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate,
 * unless dstsize is 0 or the original dst string was longer than dstsize.
 * If the src and dst strings overlap, the behavior is undefined.
 *
 * @param dst The string to add upon.
 * @param src The string to append.
 * @param dstsize The allocated size of dst.
 * @return The total length of the string to be created.
 * (This may differ from the size of the string actually created)
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (src[i] != '\0' && dstsize - dstlen - 1 > i)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}
