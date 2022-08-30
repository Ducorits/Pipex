/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 12:51:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:35:51 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for whitespace characters.
 *
 * @param c The character to test.
 * @return 1 if 'c' is a whitespace character, 0 otherwise.
 */
int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f');
}
