#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	char		*buffer;
	struct list	*next;
}	t_list;
size_t	count_to_new_line(t_list *list);
void	copy_to(t_list *list, char *str);
t_list	*get_last_node(t_list *list);
void	add_node(t_list **list, char *buffer);
char	*get_line(t_list *list);
void	free_list(t_list **list);
void	create_list(t_list **list, int fd);
char	*get_next_line(int fd);
void	__del_al__(t_list **list, t_list *node);
int		check_new_line(t_list *list);
#endif
