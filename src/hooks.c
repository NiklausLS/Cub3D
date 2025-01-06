#include "../includes/cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	printf("%i\n", keycode);
	if (keycode == KEY_W)
		game->player.move_forward = 1;
	if (keycode == KEY_S)
		game->player.move_backward = 1;
	if (keycode == KEY_A)
		game->player.move_left = 1;
	if (keycode == KEY_D)
		game->player.move_right = 1;
	if (keycode == KEY_LEFT)
		game->player.rotate_left = 1;
	if (keycode == KEY_RIGHT)
		game->player.rotate_right = 1;
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.move_forward = 0;
	if (keycode == KEY_S)
		game->player.move_backward = 0;
	if (keycode == KEY_A)
		game->player.move_left = 0;
	if (keycode == KEY_D)
		game->player.move_right = 0;
	if (keycode == KEY_LEFT)
		game->player.rotate_left = 0;
	if (keycode == KEY_RIGHT)
		game->player.rotate_right = 0;
	return (0);
}
