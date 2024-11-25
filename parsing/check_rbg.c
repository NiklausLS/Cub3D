/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rbg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:18:33 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/25 13:28:04 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//check si les couleurs sont entre 0 et 255

/*
 * check if rgb color for ground and ceiling are ok
 */
void	get_rgb_path(t_data *data, char *file)
{
	int		fd;
	char	*line;

	printf("START get_rbg_path\n");
	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
		{
			data->floor = ft_strdup(line);
			printf("F = %s\n", data->floor);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			data->ceiling = ft_strdup(line);
			printf("C = %s\n", data->ceiling);
		}
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	printf("END of get_rbg_path\n");
}

/*
 * check if the number is between 0 and 255
 */
/*static int	check_nbr(char *nbr)
{
	int	res;
	int i;

	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (1);
		i++;
	}
	res = ft_atoi(nbr);
	if (res < 0 || res > 255)
		return (1);
	return (0);
}*/

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
		printf("rbg_array[%d] = %s\n", i, rbg_array[i]);
		i++;
	}
	if (i != 3)
	{
		free_array(rbg_array);
		return (1);
	}
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
