/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:41:04 by chuchard          #+#    #+#             */
/*   Updated: 2025/01/29 06:15:48 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		bytes_per_pixel;

	bytes_per_pixel = img->bpp / 8;
	pixel = img->data + (y * img->size_line) + (x * bytes_per_pixel);
	if (img->endian == 0)
	{
		pixel[0] = (color) & 0xFF;
		pixel[1] = (color >> 8) & 0xFF;
		pixel[2] = (color >> 16) & 0xFF;
	}
	else
	{
		pixel[0] = (color >> 16) & 0xFF;
		pixel[1] = (color >> 8) & 0xFF;
		pixel[2] = (color) & 0xFF;
	}
}

void	render_ceiling_and_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel_to_image(&game->img, x, y, game->ceiling_color);
			else
				put_pixel_to_image(&game->img, x, y, game->floor_color);
			x++;
		}
		y++;
	}
	x = 0;
}

t_texture	*define_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (&game->textures[0]);
	else if (ray->side == 0 && ray->dir_x < 0)
		return (&game->textures[1]);
	else if (ray->side == 1 && ray->dir_y > 0)
		return (&game->textures[2]);
	else
		return (&game->textures[3]);
}
