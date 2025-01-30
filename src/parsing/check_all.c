/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:08:23 by nileempo          #+#    #+#             */
/*   Updated: 2025/01/30 12:22:59 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//finir wall sur le côté
//check si on peut parcourir tous les 1 du bord

int	check_all(int argc, char **argv, t_data *data)
{
	if (!argv || !data)
		return (1);
	if (check_argc(argc) == 1)
		return (1);
	if (check_if_dir(argv[1]) == 1)
		return (1);
	if (check_file_end(argv[1]) == 1)
		return (1);
	if (check_last_elem(argv[1]) == 1)
		return (1);
	if (check_rbg(data, argv[1]) == 1)
		return (1);
	if (check_map(data, argv[1]) == 1)
		return (1);
	if (check_textures(data, argv[1]) == 1)
		return (1);
	print_data(data);
	return (0);
}

int	last_check(int argc, char **argv, t_game *game)
{
	t_data	data;

	init_data(&data);
	if (check_all(argc, argv, &data) == 1)
	{
		free_data(&data);
		return (1);
	}
	init_end_parsing(game, &data);
	free_data(&data);
	return (0);
}
