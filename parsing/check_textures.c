/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:42:48 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/31 15:25:35 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_textures(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = protected_open(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			data->north = ft_strdup(line + 3);
			printf("data->north = %s\n", data->north);
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			data->south = ft_strdup(line + 3);
			printf("data->south = %s\n", data->south);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			data->west = ft_strdup(line + 3);
			printf("data->weast = %s\n", data->west);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			data->east = ft_strdup(line + 3);
			printf("data->east = %s\n", data->east);
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("END of check_textures\n");
}