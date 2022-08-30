/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 19:12:38 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/20 18:53:26 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The isalnum() function tests for any character
 * for which isalpha() or isdigit() is true.
 *
 * @param c The character to test.
 * @return 1 if 'c' is an alphanumerical character, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
