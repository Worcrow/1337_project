/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:09:05 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/01 23:41:38 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
char	*get_next_line(int fd);
int	ft_strjoin(char **str1, char *str2);
char	*__realloc__(char **str, char *st2, size_t len1, size_t len2);
size_t	ft_strlen(char *str);
int	empty_buffer(char *buffer);
void	__remake_buffer__(char *buffer);
void	ft_copy(char *str1, char *str2);
int	check_nl(char *buffer);
#endif
