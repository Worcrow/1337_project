/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:59:00 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/06 01:44:42 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstadd_back - Adds the node ’new’ at the end of the list
 * @lst: The address of a pointer to the first link of a list
 * @new: he address of a pointer to the node to be added to the list
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = new;
	else
		*lst = new;
}
