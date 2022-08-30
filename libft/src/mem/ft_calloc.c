/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 14:41:16 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:42:11 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates enough space for count objects that are size bytes
 * of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 *
 * @param count Amount of objects to allocate.
 * @param size Byte size of objects to allocate.
 * @return Pointer to newly allocated memory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
