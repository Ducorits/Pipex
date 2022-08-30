/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:19:02 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/09 13:05:12 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}
