/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2darlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 14:18:41 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/22 14:39:26 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Takes a NULL terminated 2d array and returns
 * the amount of arrays in it.
 *
 * @param pointer The 2d array to measure.
 * @return The total "length" of the 2d array. */
int	ft_2darlen(void **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		i++;
	}
	return (i);
}
