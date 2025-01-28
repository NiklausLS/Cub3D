/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:42:48 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/24 00:10:16 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		{
			data->north = ft_strdup(line + 3);
			//printf("data->north = %s\n", data->north);
		}
		else if (ft_strncmp(tmp, "SO ", 3) == 0)
		{
			data->south = ft_strdup(line + 3);
			//printf("data->south = %s\n", data->south);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			data->west = ft_strdup(line + 3);
			//printf("data->weast = %s\n", data->west);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			data->east = ft_strdup(line + 3);
			//printf("data->east = %s\n", data->east);
		}
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	close (fd);
	//printf("END of check_textures\n");
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
	//printf("check_textures OK\n");
	return (0);
}

int	check_t_path(char *str)
{
	char	*tmp;
	int		i;
	//int		fd;

	tmp = ft_strtrim(str, " \n");
	if (!tmp)
		return (1);
	i = ft_strlen(tmp);
	/*fd = protected_open(tmp);
	if (fd == -1)
	{
		write (2, "ERROR\nCan't be opened.\n", 24);
		return (1);
	}*/
	//printf("tmp = %s\n", tmp);
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
