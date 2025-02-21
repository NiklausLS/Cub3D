/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rbg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:18:33 by nileempo          #+#    #+#             */
/*   Updated: 2025/02/21 16:48:39 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//check si les couleurs sont entre 0 et 255

/*
 * check if rgb color for ground and ceiling are ok
 */
void	get_rgb_path(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			data->floor = ft_strdup(line + 2);
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			data->start_map = ft_strdup(line);
			data->ceiling = ft_strdup(line + 2);
		}
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

/*
 * check if the number is between 0 and 255
 */
static int	check_nbr(char *nbr)
{
	int		res;
	int		i;
	char	*trim;

	i = 0;
	trim = ft_strtrim(nbr, " \t\n\r");
	if (!trim)
		return (1);
	while (trim[i])
	{
		if (!ft_isdigit(trim[i]))
		{
			free(trim);
			return (1);
		}
		i++;
	}
	res = ft_atoi(trim);
	free(trim);
	if (res == 0)
		return (0);
	if (res < 0 || res > 255)
		return (1);
	return (0);
}

static int	check_split_rbg(char *nbr)
{
	char	**rbg_array;
	int		i;

	i = 0;
	rbg_array = ft_split(nbr, ',');
	if (!rbg_array)
		return (1);
	while (rbg_array[i])
	{
		if (check_nbr(rbg_array[i]) == 1)
		{
			free_array(rbg_array);
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		free_array(rbg_array);
		return (1);
	}
	free_array(rbg_array);
	return (0);
}

int	check_rbg(t_data *data, char *file)
{
	get_rgb_path(data, file);
	if (!data->floor || !data->ceiling)
	{
		ft_putstr_fd("Error\nA color is missing.\n", 2);
		return (1);
	}
	if ((check_split_rbg(data->floor) == 1)
		|| (check_split_rbg(data->ceiling) == 1))
	{
		ft_putstr_fd("Error\nInvalid RGB color\n", 2);
		return (1);
	}
	return (0);
}

/*
 * Turns chars into int for mate
 */
int	get_rgb_value(char *str)
{
	char	**array;
	int		rgb[3];
	int		res;

	array = ft_split(str, ',');
	if (!array)
		return (0);
	get_rgb(array, rgb);
	res = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	free_array(array);
	return (res);
}
