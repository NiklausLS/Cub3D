/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:22 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/31 15:17:28 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_data(t_data *data)
{
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->floor);
	free(data->ceiling);
}
