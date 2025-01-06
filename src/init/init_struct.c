/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:13:22 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/07 00:13:31 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//init everything to null in data structure
void	init_data(t_data *data)
{
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->floor = NULL;
	data->ceiling = NULL;

	data->mlx = NULL;
	data->window = NULL;

	data->player = 0;
	data->map = NULL;
	data->start_map = NULL;
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	/*if (data->north)
		printf("data->north = %s\n", data->north);
	if (data->south)
		printf("data->south = %s\n", data->south);
	if (data->west)
		printf("data->west= %s\n", data->west);
	if (data->east)
		printf("data->east = %s\n", data->east);
	if (data->floor)
		printf("data->floor = %s\n", data->floor);
	if (data->ceiling)
		printf("data->ceiling = %s\n", data->ceiling);
	if (data->player)
		printf("data->player = %d\n", data->player);*/
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s\n", data->map[i]);
			i++;
		}
	}
}
