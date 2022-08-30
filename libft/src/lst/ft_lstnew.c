/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 13:08:47 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/08 00:26:39 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
