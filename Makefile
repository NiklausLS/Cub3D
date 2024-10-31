# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 20:22:49 by nileempo          #+#    #+#              #
#    Updated: 2024/10/31 15:30:33 by nileempo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c \
	init/init_struct.c \
	free/free_data.c\
	parsing/check_file.c \
	parsing/protected_open.c \
	parsing/check_textures.c \
	parsing/check_all.c \

FLAGS = -Wall -Werror -Wextra

CC = clang

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L./libft -lft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re