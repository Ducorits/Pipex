/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 15:35:06 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 01:15:55 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitcount(char *str, char c)
{
	while (*str == c && *str)
		str++;
	if (!(*str))
		return (0);
	while (*str && *str != c)
		str++;
	return (1 + splitcount(str, c));
}

static int	part_length(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*fill_part(char *str, char **dst, char c)
{
	int	len;

	while (*str == c)
		str++;
	len = part_length(str, c);
	*dst = ft_substr(str, 0, len);
	return (str + len);
}

static void	freeit(char **str_arr, int i)
{
	while (i > 0)
	{
		free(str_arr[i]);
		i--;
	}
	free(str_arr);
}

/**
 * @brief Allocates and returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter.
 * The array must end with a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	*str;
	char	**str_arr;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	count = splitcount(str, c);
	str_arr = (char **)malloc((count + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str = fill_part(str, &(str_arr[i]), c);
		if (str_arr[i] == NULL)
		{
			freeit(str_arr, i);
			return (NULL);
		}
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
