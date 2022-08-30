/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 15:11:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:50:45 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 *
 * @param c The character to convert.
 * @return If the argument is an upper-case letter, the function
 * returns the corresponding lower-case letter if there is one.
 * Otherwise, the argument is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
