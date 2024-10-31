/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:08:23 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/31 15:41:26 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//CHECK SI PLAYER & SI UN SEUL PLAYER
//CHECK POUR LES ESPACES VIDES

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
	printf("check_all OK\n");
	return (0);
}
