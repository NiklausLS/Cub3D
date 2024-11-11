/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rbg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:18:33 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/11 23:34:57 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

int	check_rbg(t_data *data, char *file)
{
	get_rgb_path(data, file);
	if (!data->floor || !data->ceiling)
	{
		ft_putstr_fd("Error\nA color is missing.\n", 2);
		return (1);
	}
	return (0);
}
