/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:15 by chuchard          #+#    #+#             */
/*   Updated: 2025/01/29 06:39:44 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	memset(&game, 0, sizeof(game));
	if (last_check(argc, argv, &game) == 1)
		return (1);
	if (!game.map)
		return (1);
	init_player(&game);
	init_game(&game);
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
