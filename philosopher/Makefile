# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 09:01:03 by oel-asri          #+#    #+#              #
#    Updated: 2024/12/13 09:37:23 by oel-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = _philo_
BONUS = bonus

PFLAGS = -pthread

SRCS = philo/init.c philo/main.c philo/monitor.c philo/routine_actions.c philo/threads.c philo/utils.c
SRCS_BONUS = philo_bonus/creating_data.c philo_bonus/main.c philo_bonus/routine_bonus.c philo_bonus/utils2_bonus.c philo_bonus/utils3_bonus.c philo_bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) philo/philo.h
	@$(CC) $(CFLAGS) $(PFLAGS) $(OBJS) -o $(NAME)
	@clear

$(BONUS): $(OBJS_BONUS) philo_bonus/philo_bonus.h
	@$(CC) $(CFLAGS) $(PFLAGS) $(OBJS_BONUS) -o $(BONUS)
	@clear

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@clear

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@clear

	
re: fclean all

.PHONY: all clean fclean re
