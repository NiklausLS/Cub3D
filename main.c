/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:59:13 by nileempo          #+#    #+#             */
/*   Updated: 2024/12/06 11:26:37 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

//map size ?
//touches
//finir wall sur le côté
//check si on peut parcourir tous les 1 du bord

//VOIR PROTECTIONS POUR LES MURS
//AFFICHER TEXTURES DES MURS

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (check_all(argc, argv, &data) == 1)
	{
		free_data(&data);
		return (1);
	}
	if (init_map(&data) == 1)
	{
		free_data(&data);
		return (1);
	}
	//printf("argv = %s", argv[1]);
	mlx_hook(data.window,2, 1L << 0, key_press, &data);
	mlx_hook(data.window, 17, 0, close_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
