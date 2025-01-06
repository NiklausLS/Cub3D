#include "cub3d.h"

void	update_player_position(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	new_x;
	double	new_y;

	if (game->player.move_forward)
	{
		new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
		new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
		if (game->map[(int)new_y][(int)game->player.x] != '1')
			game->player.y = new_y;
		if (game->map[(int)game->player.y][(int)new_x] != '1')
			game->player.x = new_x;
	}
	if (game->player.move_backward)
	{
		new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
		new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
		if (game->map[(int)new_y][(int)game->player.x] != '1')
			game->player.y = new_y;
		if (game->map[(int)game->player.y][(int)new_x] != '1')
			game->player.x = new_x;
	}
	if (game->player.move_left)
	{
		new_x = game->player.x - game->player.plane_x * MOVE_SPEED;
		new_y = game->player.y - game->player.plane_y * MOVE_SPEED;
		if (game->map[(int)new_y][(int)game->player.x] != '1')
			game->player.y = new_y;
		if (game->map[(int)game->player.y][(int)new_x] != '1')
			game->player.x = new_x;
	}
	if (game->player.move_right)
	{
		new_x = game->player.x + game->player.plane_x * MOVE_SPEED;
		new_y = game->player.y + game->player.plane_y * MOVE_SPEED;
		if (game->map[(int)new_y][(int)game->player.x] != '1')
			game->player.y = new_y;
		if (game->map[(int)game->player.y][(int)new_x] != '1')
			game->player.x = new_x;
	}
	if (game->player.rotate_left)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - game->player.plane_y * sin(-ROT_SPEED);
		game->player.plane_y = old_plane_x * sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
	}
	if (game->player.rotate_right)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - game->player.plane_y * sin(ROT_SPEED);
		game->player.plane_y = old_plane_x * sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
	}
}

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

void	calculate_ray_direction(t_game *game, int x, t_ray *ray)
{
	ray->dir_x = game->player.dir_x + game->player.plane_x
		* (2 * x / (double)WIN_WIDTH - 1);
	ray->dir_y = game->player.dir_y + game->player.plane_y
		* (2 * x / (double)WIN_WIDTH - 1);
}

void	initialize_ray_tracing(t_game *game, t_ray *ray)
{
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1 - game->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1 - game->player.y) * ray->delta_y;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (game->map[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

void	calculate_wall_distance_and_height(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - game->player.x + (1 - ray->step_x)
				/ 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - game->player.y + (1 - ray->step_y)
				/ 2) / ray->dir_y;
	}
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
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

void	render_column(t_game *game, int x, t_ray *ray, t_texture *tex)
{
	double	wall_x;
	int		y;
	double	step;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->dir_x;
	tex->x = (wall_x - floor(wall_x)) * tex->width;
	if ((!ray->side && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		tex->x = tex->width - tex->x - 1;
	step = (double)tex->height / ray->line_height;
	tex->pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->height - 1);
		tex->pos += step;
		tex->pix = tex->data + (tex->y * tex->line + tex->x * (tex->bpp / 8));
		put_pixel_to_image(&game->img, x, y, *(int *)tex->pix);
	}
}

int	render_frame(t_game *game)
{
	t_ray		ray;
	t_texture	*texture;
	int			x;

	x = 0;
	update_player_position(game);
	render_ceiling_and_floor(game);
	while (x < WIN_WIDTH)
	{
		calculate_ray_direction(game, x, &ray);
		initialize_ray_tracing(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance_and_height(game, &ray);
		texture = define_wall_texture(game, &ray);
		render_column(game, x, &ray, texture);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}
