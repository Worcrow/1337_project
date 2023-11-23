/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:08:02 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/22 19:52:33 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		buffer_empty(char *buffer);
int		starting_index(char *buffer);
size_t	count_size(char *buffer);
#endif
