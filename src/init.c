#include "cub3d.h"

// Temporaire
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
