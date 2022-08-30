/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printun.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:27:01 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/06 15:56:42 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printun(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count = ft_printun(n / 10);
	n = n % 10 + 48;
	write(1, &n, 1);
	return (count + 1);
}
