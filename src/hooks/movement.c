/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:48:43 by chuchard          #+#    #+#             */
/*   Updated: 2025/01/29 06:42:48 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	factor_ft_move(t_game *game, double factor_x, double factor_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + factor_x * MOVE_SPEED;
	new_y = game->player.y + factor_y * MOVE_SPEED;
	if (game->map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
	if (game->map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
}

static void	factor_ft_rot(t_game *game, int sign)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(ROT_SPEED * sign)
		- game->player.dir_y * sin(ROT_SPEED * sign);
	game->player.dir_y = old_dir_x * sin(ROT_SPEED * sign) + game->player.dir_y
		* cos(ROT_SPEED * sign);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(ROT_SPEED * sign)
		- game->player.plane_y * sin(ROT_SPEED * sign);
	game->player.plane_y = old_plane_x * sin(ROT_SPEED * sign)
		+ game->player.plane_y * cos(ROT_SPEED * sign);
}

void	update_player_position(t_game *game)
{
	if (game->player.move_forward)
		factor_ft_move(game, game->player.dir_x, game->player.dir_y);
	if (game->player.move_backward)
		factor_ft_move(game, -game->player.dir_x, -game->player.dir_y);
	if (game->player.move_left)
		factor_ft_move(game, -game->player.plane_x, -game->player.plane_y);
	if (game->player.move_right)
		factor_ft_move(game, game->player.plane_x, game->player.plane_y);
	if (game->player.rotate_left)
		factor_ft_rot(game, -1);
	if (game->player.rotate_right)
		factor_ft_rot(game, 1);
}
