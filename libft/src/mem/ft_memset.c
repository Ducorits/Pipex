/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 12:11:18 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:12:56 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes len bytes of value c
 * (converted to an unsigned char) to the string b.
 *
 * @param b The string to write to.
 * @param c The value to write with.
 * @param len The amount of bytes to write.
 * @return The pointer b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = b;
	while (len > 0)
	{
		len--;
		*a = c;
		a++;
	}
	return (b);
}
