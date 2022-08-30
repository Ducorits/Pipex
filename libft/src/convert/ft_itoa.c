/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 15:12:08 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/20 13:30:03 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	asize(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*fill_str(char *str, unsigned int n, int len)
{
	if (n >= 10)
	{
		fill_str(str, n / 10, len - 1);
	}
	str[len - 1] = n % 10 + 48;
	return (str);
}

/**
 * @brief Allocates and returns a string representing the
 * integer received as an argument.
 *
 * @param n The integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	ncpy;

	len = asize(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		ncpy = n * -1;
		str = fill_str(str, ncpy, len);
		*str = '-';
	}
	else
	{
		ncpy = n;
		str = fill_str(str, ncpy, len);
	}
	str[len] = '\0';
	return (str);
}
