/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/14 19:25:23 by dritsema      #+#    #+#                 */
/*   Updated: 2022/08/11 15:26:22 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The ft_atoi() function converts the initial portion of the
 * string pointed to by str to int representation.
 *
 * @param str The string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				mins;

	n = 0;
	mins = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		mins = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	return ((int)(n * mins));
}
