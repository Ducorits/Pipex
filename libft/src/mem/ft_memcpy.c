/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:18:00 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:08:21 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dst.
 * If dst and src overlap, behavior is undefined (Try ft_memmove).
 *
 * @param dst The memory to copy to.
 * @param src The memory to copy from.
 * @param n The amount of bytes to copy.
 * @return The original value of dst (pointer).
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		((unsigned char *) dst)[i] = ((const unsigned char *) src)[i];
		i++;
		n--;
	}
	return (dst);
}
