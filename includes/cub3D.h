/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:29 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/02 00:18:17 by nileempo         ###   ########.fr       */
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
# include "../minilibx/minilibx_linux/mlx.h"
# include "../minilibx/minilibx_mac/mlx.h"

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

}	t_data;

//INIT FUNCTIONS
void	init_data(t_data *data);
int		init_map(t_data *data);

//FREE FUNCTIONS
void	free_data(t_data *data);

//PARSING FUNCTIONS
int	check_if_dir(char *file);
int	check_argc(int argc);
int	check_file_end(char *str);
int	check_elements(char *file);
//int	check_player(char *file);

int	check_textures(t_data *data, char *file);
int	check_all(int argc, char **argv, t_data *data);

//PROTECTED FUNCTIONS
int	protected_open(char *str);

//EVENTS FUNCTIONS
int	close_game(t_data *data);

#endif