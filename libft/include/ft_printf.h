/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:37:12 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/18 22:23:42 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *s, ...);
int	ft_printhex(unsigned long n);
int	ft_upprinthex(unsigned long n);
int	ft_printun(unsigned int n);
int	ft_printchar(char c);
int	ft_printnbr(int n);
int	ft_printstr(char *s);

#endif // FT_PRINTF_H
