NAME = cub3d

SRCS = src/main.c \
	src/hooks/hooks.c \
	src/hooks/movement.c \
	src/render/render.c \
	src/render/render_utils.c \
	src/parsing/check_file.c \
	src/parsing/protected_open.c \
	src/parsing/check_textures.c \
	src/parsing/check_rbg.c \
	src/parsing/check_borders.c \
	src/parsing/check_all.c \
	src/parsing/check_map.c \
	src/parsing/check_elements.c \
	src/parsing/trim_rgb.c \
	src/parsing/check_copy.c \
	src/init/init_struct.c \
	src/init/init_map.c \
	src/init/init.c \
	src/free/free_data.c \

OBJ = $(SRCS:.c=.o)
CC = gcc

ifeq ($(shell uname), Darwin)
	MLX_DIR = minilibx/minilibx_mac
	MLX_FLAGS = -L minilibx/minilibx_mac -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx/minilibx_linux
	MLX_FLAGS = -L minilibx/minilibx_linux -lmlx -lX11 -lXext -lm
endif

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) $(CFLAGS) -o $(NAME) $(OBJ) -L./libft -lft $(MLX_FLAGS)

clean:
	make clean -C ./libft
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
