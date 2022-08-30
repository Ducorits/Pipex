/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:43:41 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/16 14:00:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdarg.h>

static int	doit(va_list args, const char **s)
{
	int	count;

	count = 0;
	if ((*s)[1] == 'i')
		count = ft_printnbr(va_arg(args, int));
	else if ((*s)[1] == 'd')
		count = ft_printnbr(va_arg(args, int));
	else if ((*s)[1] == 'u')
		count = ft_printun(va_arg(args, unsigned int));
	else if ((*s)[1] == 's')
		count = ft_printstr(va_arg(args, char *));
	else if ((*s)[1] == 'c')
		count = ft_printchar(va_arg(args, int));
	else if ((*s)[1] == 'x')
		count = ft_printhex(va_arg(args, unsigned int));
	else if ((*s)[1] == 'X')
		count = ft_upprinthex(va_arg(args, unsigned int));
	else if ((*s)[1] == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_printhex(va_arg(args, unsigned long));
	}
	else if ((*s)[1] == '%')
		count = ft_printchar('%');
	return (count);
}

/**
 * @brief A function that mimic's the original printf().
 * But with far less features.
 *
 * @param s The string to parse.
 * @param ... The individual arguments to insert into the string.
 * @return The amount of characters printed.
 */
int	ft_printf(const char *s, ...)
	{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += doit(args, &s);
			s += 2;
		}
		else
		{
			ft_printchar(*s);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
