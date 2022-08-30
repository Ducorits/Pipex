/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 19:05:17 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:22:50 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any character for which
 * ft_isupper() or ft_islower() is true.
 *
 * @param c The character to test.
 * @return 1 if 'c' is an alphabetical character, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
