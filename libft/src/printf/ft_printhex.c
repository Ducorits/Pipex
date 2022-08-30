/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:20:46 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/09 14:08:05 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printhex(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count = ft_printhex(n / 16);
	}
	if ((n % 16) < 10)
	{
		n = (n % 16) + 48;
		write(1, &n, 1);
		count++;
	}
	if ((n % 16) >= 10)
	{
		n = (n % 16) - 10 + 'a';
		write(1, &n, 1);
		count++;
	}
	return (count);
}
