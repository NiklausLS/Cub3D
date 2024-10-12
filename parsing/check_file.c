/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:58:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/12 20:47:07 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
// check if it's not a directory
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

// check if it can be opened
