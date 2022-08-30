/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 17:16:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:16:03 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes a node, frees the memory of the node’s content
 * using the function ’del’ and then frees the node.
 * The memory of ’next’ will not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		del(lst->content);
	free(lst);
}
