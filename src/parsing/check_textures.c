/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:42:48 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/30 12:30:04 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 * Check if all cardinal textures are there
 */
static void	get_textures_path(t_data *data, char *file)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strtrim(line, " \n");
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			data->north = ft_strdup(tmp + 3);
		else if (ft_strncmp(tmp, "SO ", 3) == 0)
			data->south = ft_strdup(tmp + 3);
		else if (ft_strncmp(tmp, "WE ", 3) == 0)
			data->west = ft_strdup(tmp + 3);
		else if (ft_strncmp(tmp, "EA ", 3) == 0)
			data->east = ft_strdup(tmp + 3);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	close (fd);
}

/*
 * Check if all cardinal textures are there
 */
int	check_textures(t_data *data, char *file)
{
	get_textures_path(data, file);
	if (!data->north || !data->south ||!data->west
		|| !data->east)
	{
		ft_putstr_fd("Error\nA texture path is missing.\n", 2);
		return (1);
	}
	if (check_t_path(data->east) == 1 || check_t_path(data->west) == 1
		|| check_t_path(data->north) == 1 || check_t_path(data->south) == 1)
		return (1);
	return (0);
}

int	check_t_path(char *str)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(str, " \n");
	if (!tmp)
		return (1);
	i = ft_strlen(tmp);
	if (i < 4 || tmp[i - 4] != '.' || tmp[i - 3] != 'x' || tmp[i - 2] != 'p'
		|| tmp[i - 1] != 'm')
	{
		write (2, "ERROR\nThis is not a .xpm texture.\n", 35);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
