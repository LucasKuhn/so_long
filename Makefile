NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLXFLAGS) main.c -o $(NAME)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

