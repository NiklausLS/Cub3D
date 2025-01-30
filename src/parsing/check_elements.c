/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:33:12 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/30 12:26:27 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_wrongs_elem(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (0);
	else
		ft_putstr_fd("ERROR:\nWrong element in map\n", 2);
	return (1);
}

static int	check_player_nbr(t_data *data)
{
	if (data->player != 1)
	{
		ft_putstr_fd("ERROR\nWrong number of player\n", 2);
		return (1);
	}
	return (0);
}

int	check_player(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] && map[i + 1])
	{
		j = 1;
		while (map[i][j] && map[i][j + 1])
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
	if (check_player_nbr(data) == 1)
		return (1);
	return (0);
}

static int	map_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == ' ' || line[0] == '\n' || line[0] == '\t')
		return (0);
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E'
		|| line[0] == 'W' || line[0] == 'F' || line[0] == 'C')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
 * Check if the last elements of the file is the map
 */
int	check_last_elem(char *file)
{
	char	*line;
	int		fd;
	int		last_map;

	last_map = 0;
	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!map_line(line))
			last_map = 1;
		else if (last_map == 1)
		{
			free(line);
			close(fd);
			ft_putstr_fd("Error\nMap is not last in the file.\n", 2);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
