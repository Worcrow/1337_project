CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find src -type f -name '*.c') ft_printf.c
OBJ = $(SRC:.c=.o)

HEADER = include/function_used.h ft_printf.h
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $@ $^

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)


fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all Clean Fclean Re
