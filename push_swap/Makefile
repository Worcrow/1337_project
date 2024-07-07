SRC=$(shell find src -name '*.c')
OBJ=$(SRC:.c=.o)

SRC_BONUS=$(shell find checker_bonus -name '*.c')
OBJ_BONUS=$(SRC_BONUS:.c=.o)
BONUS=checker

NAME=push_swap
CFLAGS= -Wall -Wextra -Werror
CC=cc


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) include/push_swap.h

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

$(OBJ_BONUS): $(SRC_BONUS) checker_bonus/include_bonus/push_swap_bonus.h

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -rf $(NAME) $(BONUS)
re: fclean all

.PHONY: clean re fclean all