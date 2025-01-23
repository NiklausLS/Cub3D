/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:08:23 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/20 22:19:02 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//finir wall sur le côté
//check si on peut parcourir tous les 1 du bord

int	check_all(int argc, char **argv, t_data *data)
{
	if (check_argc(argc) == 1)
		return (1);
	//printf("after check_argc\n");
	if (check_if_dir(argv[1]) == 1)
		return (1);
	//printf("after check_if_dir\n");
	if (check_file_end(argv[1]) == 1)
		return (1);
	//printf("after check_file_end\n");
	if (check_textures(data, argv[1]) == 1)
		return (1);
	printf("after check_textures\n");
	if (check_rbg(data, argv[1]) == 1)
		return (1);
	printf("after check_rbg\n");
	if (check_map(data, argv[1]) == 1)
		return (1);
	printf("after check_map\n");
	print_data(data);
	printf("check_all OK\n");
	return (0);
}

/*static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		//printf("%c", line[i]);
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != '\n')
			return (1);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			if (i == 0 || line [i + 1] == '\0' || line [i + 1] == '\n')
				return (1);
			if (line[i + 1] != '0' && line[i + 1] != '1' && line[i + 1] != ' '
				&& line[i - 1] != '0' && line[i - 1] != '1' && line[i - 1] != ' ')
				return (1);
		}
		line++;
	}
	return (0);
}*/

/*int	get_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;


	printf("in get_map\n");
	i = 0;
	fd = protected_open(file);
	line = get_next_line(fd);
	data->map = (char **)malloc(sizeof(char *)
			* (line_nbr(data->start_map, file) + 1));
	if (!data->map)
		return (1);
	line = get_next_line(fd);
	//int j = 0;
	//puts("test");
	while (line != NULL)
	{
		//puts("loop");
		//printf("line %d = %s\n", j, line);
		//j++;
		if (ft_strncmp(line, data->start_map, ft_strlen(data->start_map)))
		{
			//printf("data->stat_map = %s\n", data->start_map);
			//printf("line = %s\n", line);
			//printf("data->start_map = %s\n", data->start_map);
			free(line);
			line = get_next_line(fd);
			while (line != NULL)
			{
				data->map[i++] = ft_strdup(line);
				//printf("MAP line = %s\n", line);
				free(line);
				line = get_next_line(fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close (fd);
	printf("get_map OK\n");
	print_data(data);
	return (0);
}*/

int	last_check(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (check_all(argc, argv, &data) == 1)
	{
		printf("ERROR CHECK ALL\n");
		free_data(&data);
		return (1);
	}
	free_data(&data);
	return (0);
}
