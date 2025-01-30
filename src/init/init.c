/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:42:06 by chuchard          #+#    #+#             */
/*   Updated: 2025/01/29 06:42:07 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].img_ptr = mlx_xpm_file_to_image(game->mlx,
				game->textures[i].path, &game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img_ptr)
		{
			fprintf(stderr, "Error loading texture: %s\n",
				game->textures[i].path);
			exit(1);
		}
		game->textures[i].data = mlx_get_data_addr(game->textures[i].img_ptr,
				&game->textures[i].bpp, &game->textures[i].line,
				&game->textures[i].endian);
		i++;
	}
}

static void	init_player_2(t_game *game, int x, int y)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (game->map[y][x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map[y][x] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map[y][x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->map[y][x] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = -game->player.dir_y * FOV;
	game->player.plane_y = game->player.dir_x * FOV;
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				init_player_2(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		fprintf(stderr, "Erreur: Impossible d'initialiser MiniLibX\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
	{
		fprintf(stderr, "Erreur: Impossible de créer une fenêtre\n");
		return (0);
	}
	return (1);
}
