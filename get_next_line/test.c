/***************************************************************************/
/*									   */
/*									   */
/*				__      _____  _ __ ___ _ __ _____      __ */
/*	By: worcrow		\ \ /\ / / _ \| '__/ __| '__/ _ \ \ /\ / / */
/*		 	 	 \ V  V / (_) | | | (__| | | (_) \ V  V /  */
/*	worcrow@worcrow-12	  \_/\_/ \___/|_|  \___|_|  \___/ \_/\_/   */
/*								   	   */
/*									   */
/*									   */
/***************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

void	print_list(t_list *list)
{
	int i;

	i = 1;
	if (!list)
		printf("NONE HERE\n");
	while (list)
	{
		printf("------node%d: %s------", i, list->buffer);
		list = list->next;
	}
}

int main(void)
{
	t_list *list;
	int fd = open("file.txt", O_RDONLY);
	list = NULL;
	create_list(&list, fd);
	print_list(list);
	free_list(&list);
	printf("next_call:\n\n");
	print_list(list);
	return (0);
}
