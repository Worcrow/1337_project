SRC=event_handler.c fractol.c fractol_utils.c julia.c main.c mandelboart.c
SRC_BONUS = $(shell find bonus_dir -name '*.c')

OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)

CC=cc
CFLAGS= -Wall -Wextra -Werror -Imlx
LINKS_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit 
NAME=fractol

all: $(NAME)
	@$(CC) $(OBJ) $(LINKS_FLAGS) -o $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)

bonus: fractol_bonus
	@$(CC) $(OBJ_BONUS) $(LINKS_FLAGS) -o $<

fractol_bonus: $(OBJ_BONUS)

$(OBJ_BONUS): $(SRC_BONUS)


clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -rf $(NAME) fractol_bonus
re: fclean all

.phony: clean fclean re
