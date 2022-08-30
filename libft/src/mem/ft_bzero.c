/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:16:42 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:31:58 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes n zeroed bytes to the string s. If n is zero, do nothing.
 *
 * @param s String to write to.
 * @param n Amount to write.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = s;
	while (n > 0)
	{
		*a = '\0';
		a++;
		n--;
	}
}
