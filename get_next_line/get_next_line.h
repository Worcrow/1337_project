/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:20:00 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/14 09:15:00 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_ln(char *buffer);
char	*ft_strjoin(char **str1, char *str2);
char	*remake_buffer(char *buffer);
char	*ft_strchr(const char *src, int c);
size_t	ft_strlen(const char *str);
#endif
