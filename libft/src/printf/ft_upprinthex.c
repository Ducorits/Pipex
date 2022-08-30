/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_upprinthex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:26:18 by dritsema      #+#    #+#                 */
/*   Updated: 2021/12/10 14:02:43 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_upprinthex(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count = ft_upprinthex(n / 16);
	}
	if ((n % 16) < 10)
	{
		n = (n % 16) + 48;
		write(1, &n, 1);
		count++;
	}
	if ((n % 16) >= 10)
	{
		n = (n % 16) - 10 + 'A';
		write(1, &n, 1);
		count++;
	}
	return (count);
}
