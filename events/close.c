/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:14:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/02 00:25:41 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * This function will close the game when user clic on cross
 */
int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	//free_data(data);
	exit(0);
}
