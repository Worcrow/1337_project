#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
size_t	ft_strsize(const char *str);
size_t	ft_lstlen(t_list *lst);
void	*ft_lstreset(t_list *lst);

#endif

