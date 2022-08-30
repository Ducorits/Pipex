/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/23 15:57:11 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 16:26:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	recurse(unsigned int n, int fd)
{
	if (n > 9)
	{
		recurse(n / 10, fd);
	}
	n = n % 10 + 48;
	write(fd, &n, 1);
}

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ncpy;

	ncpy = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncpy = n * -1;
	}
	recurse(ncpy, fd);
}
