/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:00:01 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/09 05:13:18 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstclear - delete and free the list
 * @lst: The address of a pointer to a node
 * @del: : The address of the function used to delete the content of the node
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*previous;

	if (!lst)
		return ;
	temp = *lst;
	previous = NULL;
	if (!temp)
		return ;
	while (temp)
	{
		previous = temp;
		temp = temp->next;
		(*del)(previous->content);
		free(previous);
	}
	*lst = NULL;
}
