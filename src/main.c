#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Temporaire
char	*map_data[] = {
	"000000001111111111111111111111111",
	"000000001000000000110000000000001",
	"000000001011000001110000000000001",
	"000000001001000000000000000000001",
	"111111111011000001110000000000001",
	"100000000011000001110111111111111",
	"111101111111110111000000100010000",
	"111101111111110111010100100010000",
	"110000001101010111000000100010000",
	"100000000000000011000000000010000",
	"100000000000000000010100100010000",
	"11000001110101011111011110N011100",
	"111101110111010101011110100010000",
	"111111110111111101111111111110000", NULL};

// Temporaire
char	**load_map(void)
{
	int		rows;
	char	**map;

	rows = 0;
	while (map_data[rows])
		rows++;
	map = malloc((rows + 1) * sizeof(char *));
	if (!map)
	{
		perror("Error: malloc failed for map");
		return (NULL);
	}
	for (int i = 0; i < rows; i++)
	{
		map[i] = strdup(map_data[i]);
		if (!map[i])
		{
			perror("Error: strdup failed for map line");
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
	}
	map[rows] = NULL;
	return (map);
}

void	load_textures(t_game *game)
{
	char	*texture_paths[4] = {
		"textures/simonkraft/cobblestone_01.xpm",
		"textures/simonkraft/bookshelf_01.xpm",
		"textures/simonkraft/cobblestone.xpm",
		"textures/simonkraft/netherrack_01.xpm"};
	int		i;

	// Temporaire
	i = 0;
	memset(&game->textures, 0, sizeof(game->textures));
	while (i < 4)
	{
		game->textures[i].img_ptr = mlx_xpm_file_to_image(game->mlx,
				texture_paths[i], &game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img_ptr)
		{
			fprintf(stderr, "Error loading texture: %s\n", texture_paths[i]);
			exit(1);
		}
		game->textures[i].data = mlx_get_data_addr(game->textures[i].img_ptr,
				&game->textures[i].bpp, &game->textures[i].line,
				&game->textures[i].endian);
		i++;
	}
}

void	init_player_2(t_game *game, int x, int y)
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

int	main(int argc, char **argv)
{
	t_game	game;
	
	memset(&game, 0, sizeof(game));

	if (last_check(argc, argv) == 1)
		return (1);

	game.map = load_map();
	if (!game.map)
		return (1);
	init_player(&game);
	game.ceiling_color = 0x87CEEB; // Temporaire
	game.floor_color = 0x2F4F4F;   // Temporaire
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game.img.img_ptr = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.img.data = mlx_get_data_addr(game.img.img_ptr, &game.img.bpp,
			&game.img.size_line, &game.img.endian);
	load_textures(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
