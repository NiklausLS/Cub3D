NAME = cub3d

SRCS = src/main.c src/init.c src/hooks.c src/render.c \
	src/parsing/check_file.c src/parsing/protected_open.c \
	src/parsing/check_textures.c src/parsing/check_rbg.c \
	src/parsing/check_borders.c src/parsing/check_all.c \
	src/init/init_struct.c src/init/init_map.c \
	src/free/free_data.c\

OBJ = $(SRCS:.c=.o)
CC = gcc

ifeq ($(shell uname), Darwin)
	MLX_DIR = src/minilibx/minilibx_mac
	MLX_FLAGS = -L src/minilibx/minilibx_mac -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = src/minilibx/minilibx_linux
	MLX_FLAGS = -L src/minilibx/minilibx_linux -lmlx -lX11 -lXext -lm
endif

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft $(MLX_FLAGS)

clean:
	make clean -C ./libft
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
