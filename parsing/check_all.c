/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:08:23 by nileempo          #+#    #+#             */
/*   Updated: 2024/12/15 20:19:02 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//finir wall sur le côté
//check si on peut parcourir tous les 1 du bord

int	check_all(int argc, char **argv, t_data *data)
{
	if (check_argc(argc) == 1)
		return (1);
	if (check_if_dir(argv[1]) == 1)
		return (1);
	if (check_file_end(argv[1]) == 1)
		return (1);
	if (check_textures(data, argv[1]) == 1)
		return (1);
	if (check_rbg(data, argv[1]) == 1)
		return (1);
	if (check_map(data, argv[1]) == 1)
		return (1);
	print_data(data);
	printf("check_all OK\n");
	return (0);
}

int	get_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = protected_open(file);
	line = get_next_line(fd);
	data->map = (char **)malloc(sizeof(char *) * (9999999 + 1));
	if (!data->map)
		return (1);
	while (line != NULL)
	{
		printf("--- line = %s\n", line);
		if (ft_strlen(line) > 0 && ft_strchr("NSWE01", line[0]))
			data->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close (fd);
	printf("END of check_map\n");
	return (0);
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->north)
		printf("data->north = %s\n", data->north);
	if (data->south)
		printf("data->south = %s\n", data->south);
	if (data->west)
		printf("data->west= %s\n", data->west);
	if (data->east)
		printf("data->east = %s\n", data->east);
	if (data->floor)
		printf("data->floor = %s\n", data->floor);
	if (data->ceiling)
		printf("data->ceiling = %s\n", data->ceiling);
	if (data->player)
		printf("data->player = %d\n", data->player);
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s\n", data->map[i]);
			i++;
		}
	}
}
