/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 15:47:31 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 10:58:35 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Lexicographically compare the null-terminated strings s1 and s2.
 * compares not more than n characters.
 * Designed for comparing strings rather than binary data,
 * characters that appear after a `\0' character are not compared.
 *
 * @param s1 First String to compare against the second.
 * @param s2 Second string to compare against the first.
 * @param n The length to compare them.
 * @return An integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal to,
 * or less than the string s2.  The comparison is done using unsigned characters.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char) s1[i] == (unsigned char) s2[i]
		&& (unsigned char) s1[i] && (unsigned char) s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
