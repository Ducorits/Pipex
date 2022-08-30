/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:18:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:34:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any printing character, including space.
 *
 * @param c The character to test.
 * @return 1 if 'c' is a printable character, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
