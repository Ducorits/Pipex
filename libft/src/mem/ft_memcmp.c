/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 15:30:19 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:05:01 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n Amount of bytes to compare.
 * @return Zero if the two strings are identical,
 * otherwise returns the difference between the first two differing bytes.
 * Zero-length strings are always identical.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
