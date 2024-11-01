/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:59:13 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/02 00:12:10 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

//map size ?
//touches

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
	printf("argv = %s", argv[1]);
	mlx_loop(data.mlx);

	free_data(&data);
	return (0);
}
