/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:05:17 by nileempo          #+#    #+#             */
/*   Updated: 2024/12/15 20:22:12 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//TO DO
//ISOLER LA MAP
// SUPPRIMER CE QUI EST DEJA CHECK OU CHERCHER DEBUT MAP ?

static int	check_wrongs_elem(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ')
		return (0);
	else
		ft_putstr_fd("ERROR:\nWrong element is map\n", 2);
	return (1);
}

static int	check_top_bot(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !map[0])
	{
		ft_putstr_fd("ERROR:\n Map is invalid\n", 2);
		return (1);
	}
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (1);
	}
	//printf("map = [0][%d]\n", i);
	while (map[i])
		i++;
	i--;
	while (map[i][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (1);
	}
	return (0);
}

static int	check_middle(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_wrongs_elem(map[i][j]) == 1)
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				data->player++;
			j++;
		}
		i++;
	}
	if (data->player != 1)
	{
		ft_putstr_fd("ERROR\nWrong number of player\n", 2);
		return (1);
	}
	return (0);
}

static int	check_walls(char **map)
{
	int	i;
	int	right;

	i = 0;
	while (map[i])
	{
		right = 0;
		while (map[i][right])
			right++;
		right--;
		if (map[i][0] != '1' && map[i][0] != ' ')
		{
			ft_putstr_fd("ERROR:\nWall is invalid\n", 2);
			return (1);
		}
		if (map[i][right] != '1' && map[i][right] != ' ')
		{
			ft_putstr_fd("ERROR:\nWall is invalid\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map(t_data *data, char *file)
{
	get_map(data, file);
	if (check_top_bot(data->map) == 1)
		return (1);
	if (check_middle(data, data->map) == 1)
		return (1);
	if (check_walls(data->map) == 1)
		return (1);
	return (0);
}