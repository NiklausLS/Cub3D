/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:01:27 by nileempo          #+#    #+#             */
/*   Updated: 2025/03/16 22:03:47 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	check_spaces(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == ' ' || copy[i][j] == '\n')
				copy[i][j] = 'X';
			j++;
		}
		i++;
	}
}

static int	check_valid_cell(char **copy, int i, int j, int row_count)
{
	if (copy[i][j] == '0' || copy[i][j] == 'N' || copy[i][j] == 'S'
		|| copy[i][j] == 'E' || copy[i][j] == 'W')
	{
		if (check_walls(copy, i, j, row_count))
		{
			ft_putstr_fd("ERROR:\nMap is not closed\n", 2);
			return (1);
		}
	}
	return (0);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		height;
	int		i;

	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_copy(t_data *data)
{
	int		i;
	int		j;
	int		row_count;

	data->map_copy = copy_map(data->map);
	if (!data->map_copy)
		return (1);
	row_count = get_height(data->map_copy);
	check_spaces(data->map_copy);
	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (check_valid_cell(data->map_copy, i, j, row_count) == 1)
				return (1);
			j++;
		}
		i++;
	}
	print_map(data->map_copy);
	return (0);
}
