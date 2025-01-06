/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:58:08 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/02 13:14:40 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * check if it's not a directory
 */
int	check_if_dir(char *file)
{
	int		fd;
	char	buffer[99999];

	fd = protected_open(file);
	if (fd != -1)
	{
		if (read(fd, buffer, 1) == -1)
		{
			if (errno == EISDIR)
			{
				write (2, "Error\nThis is not a file.\n", 27);
				close (fd);
				return (1);
			}
			else
			{
				perror("Error\n");
				close (fd);
				return (1);
			}
		}
		close (fd);
	}
	return (0);
}

/*
 * Check if the map is the only argument of the program
 */
int	check_argc(int argc)
{
	if (argc < 2)
	{
		write(2, "Error\nNot enough arguments.\n", 29);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Error\nTo many arguments.\n", 26);
		return (1);
	}
	return (0);
}

/*
 * check if the file end with cub
 */
int	check_file_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] != '.' || str[i - 3] != 'c' || str[i - 2] != 'u'
		|| str[i - 1] != 'b')
	{
		write (2, "ERROR\nThis is not a .cub file.\n", 32);
		return (1);
	}
	return (0);
}
