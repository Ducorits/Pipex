/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 17:46:14 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/09 10:52:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the string ’s’,
 * and passing its index as first argument to create a new string (with malloc)
 * resulting from successive applications of ’f’
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
