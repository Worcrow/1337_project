#include "get_next_line.h"

char	*get_line(t_list *list)
{
	char	*line;
	size_t	len;

	len = count_to_new_line(list);
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	copy_to(list, line);
	return (line);
}

void	free_list(t_list **list)
{
	t_list	*last_node;
	t_list	*current_node;
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = 0;
	current_node = malloc(sizeof(t_list));
	str = malloc(BUFFER_SIZE + 1);
	last_node = get_last_node(*list);
	if (!str || !current_node)
		return ;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		++i;
	while (last_node->buffer[i] && last_node->buffer[++i])
		str[len++] = last_node->buffer[i];
	str[len] = '\0';
	current_node->buffer = str;
	current_node->next = NULL;
	__del_al__(list, current_node);
}

void	add_node(t_list **list, char *buffer)
{
	t_list	*last_node;
	t_list	*current_node;

	last_node = get_last_node(*list);
	current_node = malloc(sizeof(t_list));
	if (!current_node)
		return ;
	if (last_node == NULL)
		*list = current_node;
	else
		last_node->next = current_node;
	current_node->buffer = buffer;
	current_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	size_t	bytes_read;

	while (!check_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		add_node(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char		*line;

	line = NULL;
	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	line = get_line(list);
	free_list(&list);
	return (line);
}
