/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:05:17 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/23 21:40:37 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//TO DO
//ISOLER LA MAP
// SUPPRIMER CE QUI EST DEJA CHECK OU CHERCHER DEBUT MAP ?

static int	check_wrongs_elem(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (0);
	else
		ft_putstr_fd("ERROR:\nWrong element in map\n", 2);
	return (1);
}

static int	check_player(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_wrongs_elem(map[i][j]) == 1)
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->player++;
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (data->player != 1)
	{
		printf("data->player = %d\n", data->player);
		ft_putstr_fd("ERROR\nWrong number of player\n", 2);
		return (1);
	}
	return (0);
}

static int	check_fill(char **map, int x, int y)
{
	printf("START check_fill\n");
	if (x < 0 || y < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'M')
		return (0);
	if (map[y][x] == ' ')
		return (1);
	map[y][x] = 'M';
	if (check_fill(map, x + 1, y) || check_fill(map, x - 1, y)
		|| check_fill(map, x, y + 1) || check_fill(map, x, y - 1))
	{
		ft_putstr_fd("ERROR:\nMap is invalid\n", 2);
		return (1);
	}
	printf("--- END check_fill\n");
	return (0);
}

static int	check_walls(char **map)
{
	int	i;
	int	right;

	i = 0;
	printf("start check_wall\n");
	while (map[i])
	{
		right = 0;
		while (map[i][right])
			right++;
		right--;
		if (map[i][0] != '1' && map[i][0] != ' ' && map[i][0] != '\n')
		{
			ft_putstr_fd("ERROR:\nWall is invalid\n", 2);
			return (1);
		}
		if (map[i][right] != '1' && map[i][right] != ' '
			&& map[i][right] != '\n')
		{
			ft_putstr_fd("ERROR:\nWall is invalid\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map(t_data *data, char *file)
{
	char 	**copy;

	get_map(data, file);
	printf("-- after get_map\n");
	if (check_player(data, data->map) == 1)
		return (1);
	printf("-- after check_middle\n");
	if (check_walls(data->map) == 1)
		return (1);

	copy = copy_map(data->map);
	if (check_fill(copy, data->player_x, data->player_y) == 1)
		
	print_map(copy);
	free_array(copy);
	printf("-- after check_walls\n");
	return (0);
}