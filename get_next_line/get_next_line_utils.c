#include "get_next_line.h"

size_t	count_to_new_line(t_list *list)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i] && list->buffer[i] != '\n')
		{
			len++;
			i++;
		}
		if (list->buffer[i] == '\n')
			return (len + 1);
		list = list->next;
	}
	return (len);
}

void	copy_to(t_list *list, char *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i] && list->buffer[i] != '\n')
			str[len++] = list->buffer[i++];
		if (list->buffer[i] == '\n')
		{
			str[len++] = '\n';
			break ;
		}
		list = list->next;
	}
	str[len] = '\0';
}

t_list	*get_last_node(t_list *list)
{
	while (list && list->next)
	{
		list = list->next;
	}
	return (list);
}

int	check_new_line(t_list *list)
{
	size_t	i;

	while (list)
	{
		i = 0;
		while (list->buffer[i] && list->buffer[i] != '\n')
			i++;
		if (list->buffer[i] == '\n')
			return (1);
		list = list->next;
	}
	return (0);
}

void	__del_al__(t_list **list, t_list *node)
{
	t_list	*temp;

	if (!*list)
		return ;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->buffer);
		free(temp);
	}
	*list = NULL;
	if (node->buffer[0])
		*list = node;
	else
	{
		free(node->buffer);
		free(node);
	}
}
