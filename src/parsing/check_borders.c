/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:05:17 by nileempo          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:05 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_fill(char **map, int x, int y)
{
	int	ret;

	ret = 0;
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return (0);
	if (map[y][x] != '1')
		return (0);
	map[y][x] = '2';
	ret = check_fill(map, x, y + 1);
	if (!ret)
		ret = check_fill(map, x, y - 1);
	if (!ret)
		ret = check_fill(map, x + 1, y);
	if (!ret)
		ret = check_fill(map, x - 1, y);
	return (ret);
}

static int	get_first_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				map[i][j] = '9';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	flood_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (get_first_wall(map))
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' && check_fill(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_data *data, char *file)
{
	char	**copy;

	get_map(data, file);
	if (check_player(data, data->map) == 1)
		return (1);
	copy = copy_map(data->map);
	if (!copy)
		return (1);
	if (flood_walls(copy) == 1)
	{
		ft_putstr_fd("ERROR:\nMap is not surrounded\n", 2);
		free_array(copy);
		return (1);
	}
	print_map(copy);
	free_array(copy);
	return (0);
}
