# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 20:22:49 by nileempo          #+#    #+#              #
#    Updated: 2024/11/02 12:48:29 by nileempo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c \
	init/init_struct.c \
	init/init_map.c \
	free/free_data.c\
	parsing/check_file.c \
	parsing/protected_open.c \
	parsing/check_textures.c \
	parsing/check_all.c \
	events/close.c \
	events/keys.c \


FLAGS = -Wall -Werror -Wextra -fsanitize=address

CC = clang

ifeq ($(shell uname), Darwin)
	MLX_DIR = minilibx/minilibx_mac
	MLX_FLAGS = -L minilibx/minilibx_mac -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx/minilibx_linux
	MLX_FLAGS = -L minilibx/minilibx_linux -lmlx -lX11 -lXext -lm
endif

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L./libft -lft $(MLX_FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
