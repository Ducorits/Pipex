/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 17:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:11:30 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free().
 * Pointer to the list will be set to NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	lst = NULL;
}
