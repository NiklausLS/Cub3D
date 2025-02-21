/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:04:36 by nileempo          #+#    #+#             */
/*   Updated: 2025/02/21 16:50:38 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*get_rgb(char **array, int *nbr)
{
	char	*trim;

	trim = protected_trim(array[0]);
	if (trim)
		nbr[0] = ft_atoi(trim);
	else
		nbr[0] = 0;
	free(trim);
	trim = protected_trim(array[1]);
	if (trim)
		nbr[1] = ft_atoi(trim);
	else
		array[1] = 0;
	free(trim);
	trim = protected_trim(array[2]);
	if (trim)
		nbr[2] = ft_atoi(trim);
	else
		nbr[2] = 0;
	free(trim);
	return (NULL);
}
