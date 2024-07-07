# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 10:18:51 by oel-asri          #+#    #+#              #
#    Updated: 2024/05/25 10:30:51 by oel-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = client.o server.o
OBJ_BONUS = server_bonus.o minitalk_utils.o client_bonus.o
CFLAGS = -Wall -Wextra -Werror
NAME = server client
NAME_BONUS = server_bonus client_bonus

all: $(NAME)

server: server.o ft_printf
	cc $(CFLAGS) -o $@ $< ft_printf/libftprintf.a

client: client.o ft_printf
	cc $(CFLAGS) -o $@ $< ft_printf/libftprintf.a

bonus: $(NAME_BONUS)

server_bonus: ft_printf bonus/server_bonus.o bonus/minitalk_utils.o
	cc $(CFLAGS) -o $@ server_bonus.o minitalk_utils.o ft_printf/libftprintf.a

client_bonus: ft_printf bonus/client_bonus.o bonus/minitalk_utils.o 
	cc $(CFLAGS) -o $@ client_bonus.o minitalk_utils.o ft_printf/libftprintf.a

%.o: %.c
	cc -c $(CFLAGS) $?

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C ft_printf clean
fclean: clean
	rm -f $(NAME) $(NAME_BONUS) ft_printf/libftprintf.a

re: fclean all

.PHONY: ft_printf