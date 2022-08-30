/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 20:57:49 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:24:27 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.  Creates a new
 * list resulting of the successive applications of
 * the function ’f’.  The ’del’ function is used to
 * delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list.
 * NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			if (!new)
				ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
