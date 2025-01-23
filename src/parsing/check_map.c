/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:55:05 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/20 22:26:06 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	printf("-- count = %d\n", count);
	return (count);
}

static int	copy_line(t_data *data, char *line, int *i)
{
	if (!check_line(line))
	{
		data->map[*i] = ft_strdup(line);
		if (data->map[*i] == NULL)
			return (1);
		*i = *i + 1;
		return (0);
	}
	return (0);
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
		if (copy_line(data, line, &i) == 1)
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	printf("get_map OK\n");
	print_data(data);
	return (0);
}
