/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 17:54:17 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:10:32 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies len bytes from string src to string dst.
 * The two strings may overlap;
 * the copy is always done in a non-destructive manner.
 *
 * @param dst The memory to copy to.
 * @param src The memory to copy from.
 * @param len The amount of bytes to copy.
 * @return The original value of dst (pointer).
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			c_dst[i] = c_src[i];
		}
	}
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
