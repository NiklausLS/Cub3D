/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:55:05 by nileempo          #+#    #+#             */
/*   Updated: 2025/03/16 21:55:57 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*int	check_player(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
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
		ft_putstr_fd("ERROR:\nInvalid player count\n", 2);
		return (1);
	}
	return (0);
}*/

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

static int	count_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!check_line(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	get_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->map = malloc(sizeof(char *) * (count_line(file) + 1));
	if (!data->map)
		return (1);
	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!check_line(line))
		{
			data->map[i] = ft_strdup(line);
			if (data->map[i] == NULL)
				return (1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

int	check_map(t_data *data, char *file)
{
	if (get_map(data, file) == 1)
		return (1);
	if (check_player(data, data->map) == 1)
		return (1);
	if (check_copy(data) == 1)
		return (1);
	return (0);
}
