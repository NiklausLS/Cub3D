/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:13:22 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/30 12:21:12 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//init everything to null in data structure
void	init_data(t_data *data)
{
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->floor = NULL;
	data->ceiling = NULL;
	data->player = 0;
	data->map = NULL;
	data->start_map = NULL;
	data->player_x = -1;
	data->player_y = -1;
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->north)
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
		printf("data->player = %d\n", data->player);
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s\n", data->map[i]);
			i++;
		}
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	init_end_parsing(t_game *game, t_data *data)
{
	memset(&game->textures, 0, sizeof(game->textures));
	game->map = data->map;
	game->textures[0].path = ft_strdup(data->north);
	game->textures[1].path = ft_strdup(data->south);
	game->textures[2].path = ft_strdup(data->west);
	game->textures[3].path = ft_strdup(data->east);
	game->ceiling_color = get_rgb_value(data->ceiling);
	game->floor_color = get_rgb_value(data->floor);
}
