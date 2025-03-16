/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:05:17 by nileempo          #+#    #+#             */
/*   Updated: 2025/03/16 22:08:58 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_len_above(char **copy, int i)
{
	int	len;

	if (i <= 0)
		return (0);
	len = (int)ft_strlen(copy[i - 1]);
	return (len);
}

static int	get_len_below(char **copy, int i, int row_count)
{
	int	len;

	if (i + 1 >= row_count)
		return (0);
	len = (int)ft_strlen(copy[i + 1]);
	return (len);
}

int	check_walls(char **copy, int i, int j, int row_count)
{
	int	len_current;
	int	len_above;
	int	len_below;

	len_current = (int)ft_strlen(copy[i]);
	len_above = get_len_above(copy, i);
	len_below = get_len_below(copy, i, row_count);
	if (i == 0 || i == row_count - 1 || j == 0 || j == len_current - 1)
		return (1);
	if ((i > 0 && j >= len_above) || (i + 1 < row_count && j >= len_below))
		return (1);
	if ((j > 0 && copy[i][j - 1] == 'X') || copy[i][j + 1] == 'X')
		return (1);
	if ((i > 0 && j < len_above && copy[i - 1][j] == 'X'))
		return (1);
	if ((i + 1 < row_count && j < len_below && copy[i + 1][j] == 'X'))
		return (1);
	return (0);
}
