/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printnbr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:40:28 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/09 13:25:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	recurse(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = recurse(n / 10);
	}
	n = n % 10 + 48;
	return (count + write(1, &n, 1));
}

int	ft_printnbr(int n)
{
	unsigned int	ncpy;
	int				count;

	count = 0;
	ncpy = n;
	if (n < 0)
	{
		write(1, "-", 1);
		ncpy = n * -1;
		count++;
	}
	count += recurse(ncpy);
	return (count);
}
