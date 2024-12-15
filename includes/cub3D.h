/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:29 by nileempo          #+#    #+#             */
/*   Updated: 2024/12/15 20:13:26 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "events.h"
# ifdef __APPLE__
#  include "../minilibx/minilibx_mac/mlx.h"
# elif defined(__linux__)
#  include "../minilibx/minilibx_linux/mlx.h"
# endif

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;

	void	*mlx;
	void	*window;

	int		player;
	char	**map;
}	t_data;

typedef struct s_image
{
	void	*img;
	int		height;
	int		width;
}	t_image;

//INIT FUNCTIONS
void	init_data(t_data *data);
int		init_map(t_data *data);

//FREE FUNCTIONS
void	free_data(t_data *data);
void	free_array(char **array);

//PARSING FUNCTIONS
int		check_if_dir(char *file);
int		check_argc(int argc);
int		check_file_end(char *str);
int		check_elements(char *file);
//int	check_player(char *file);
int		check_map(t_data *data, char *file);
int		get_map(t_data *data, char *file);

int		check_textures(t_data *data, char *file);
int		check_rbg(t_data *data, char *file);
int		check_all(int argc, char **argv, t_data *data);

//PROTECTED FUNCTIONS
int		protected_open(char *str);

//EVENTS FUNCTIONS
int		close_game(t_data *data);
int		key_press(int key, t_data *data);

void	print_data(t_data *data);

#endif