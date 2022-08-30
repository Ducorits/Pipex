/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 18:37:42 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:32:45 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for a decimal digit character.
 *
 * @param c The character to test.
 * @return 1 if 'c' is a decimal digit character, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
