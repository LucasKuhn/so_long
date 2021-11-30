NAME		= so_long
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
CC			= clang
CFLAGS		= 
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
LIBFT_FLAGS	= -L./libft -lft
LEAK_FLAGS	= -g3 -fsanitize=address
FLAGS		= $(LIBFT_FLAGS) $(MLXFLAGS) $(LEAK_FLAGS)
SRCS		=	movement.c map_loader.c load_images.c draw_sprites.c draw_player.c misc.c main.c
			
OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)
	./$(NAME) maps/small.ber

$(NAME):  $(OBJS) $(LIBFT_A)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(LIBFT_A):
	make --directory=$(LIBFT_DIR)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean

