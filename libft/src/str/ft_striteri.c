/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/23 11:50:47 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 12:56:43 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ on each character of the string 's',
 * passing its index as first argument.
 * Each character is passed by address to ’f’ to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	slen;
	unsigned int	i;

	if (s)
	{
		i = 0;
		slen = ft_strlen(s);
		while (i < slen)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
