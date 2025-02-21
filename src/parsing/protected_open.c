/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:42:12 by nileempo          #+#    #+#             */
/*   Updated: 2025/02/20 18:11:07 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//check if open is ok
int	protected_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error\nOpen failed\n", 19);
		return (-1);
	}
	return (fd);
}

char	*protected_trim(char *str)
{
	char	*trim;

	trim = ft_strtrim(str, " \t\n\r");
	if (!trim)
		return (NULL);
	return (trim);
}
