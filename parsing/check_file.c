/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:58:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/12 21:04:43 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
/*
 * check if it's not a directory
 */
int	check_if_dir(char *file)
{
	int		fd;
	char	buffer[99999];

	fd = protected_open(file);
	if (read(fd, buffer, 1) == -1)
	{
		if (errno == EISDIR)
		{
			perror("ERROR");
			close (fd);
			return (1);
		}
		else
		{
			perror("ERROR");
			close (fd);
			return (2);
		}
	}
	close (fd);
	return (0);
}


/*
 * Check if the map is the only argument of the program
 */
int	check_argc(int argc)
{
	if (argc < 2)
	{
		write(2, "ERROR: not enough arguments.\n", 29);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "ERROR: to many arguments.\n", 27);
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
		write (2, "ERROR: this is not a .cub file.\n", 33);
		return (1);
	}
	return (0);
}
