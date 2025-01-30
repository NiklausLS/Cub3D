/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:34:15 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/28 11:32:18 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 * Make the map window
 */
/*int	init_map(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_putstr_fd("Error\nMlx init failed.\n", 2);
		return (1);
	}
	data->window = mlx_new_window(data->mlx, 500, 500, "cub3D");
	if (data->window == NULL)
	{
		ft_putstr_fd("Error\nMlx window failed.\n", 2);
		return (1);
	}
	return (0);
}*/