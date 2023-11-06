/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:18:56 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/06 01:59:06 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstmap - apply the function f on the content of the list
 * @lst: address of a pointer to the node
 * @f: function pointer used to iterate on the list
 * @del: function pointer used to del the content if allocation fails
 * Return: new list, or NULL if Fails
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	t_list	*node;
	void	*val;

	temp = lst;
	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (temp)
	{
		val = (*f)(temp->content);
		node = ft_lstnew(val);
		if (!node)
		{
			(*del)(val);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		temp = temp->next;
	}
	return (new_list);
}
