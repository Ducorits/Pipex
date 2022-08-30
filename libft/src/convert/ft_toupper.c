/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 12:46:11 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/07 23:51:19 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 *
 * @param c The character to convert.
 * @return If the argument is a lower-case letter,
 * the function returns the corresponding upper-case letter if there is one.
 * Otherwise, the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
