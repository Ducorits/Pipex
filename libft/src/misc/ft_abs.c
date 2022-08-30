/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 14:17:37 by dritsema      #+#    #+#                 */
/*   Updated: 2022/07/19 14:21:05 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns the absolute value of an integer.
 *
 * @param num integer to get value from.
 * @return unsigned int corresponding to absolute value.
 */
unsigned int	ft_abs(int num)
{
	unsigned int	abs_value;

	if (num < 0)
		abs_value = num * -1;
	else
		abs_value = num;
	return (abs_value);
}
