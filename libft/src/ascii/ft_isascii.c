/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:35:36 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:30:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for an ASCII character, which is
 * any character between 0 and decimal 127 inclusive.
 *
 * @param c The character to test.
 * @return 1 if 'c' is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
