/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:45:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/03 05:54:09 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * handle the keyboard pression 
*/
int	key_press(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_game(data);
	/*else if (key == W_KEY)
		up
	else if (key == S_KEY)
		down
	else if (key == A_KEY)
		left
	else if (key == D_KEY)
		right*/
	return (0);
}
