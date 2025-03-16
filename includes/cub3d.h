/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:19:06 by nileempo          #+#    #+#             */
/*   Updated: 2025/03/16 21:59:39 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../minilibx/minilibx_linux/mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000
# define KEY_W        119
# define KEY_S        115
# define KEY_A        97
# define KEY_D        100
# define KEY_LEFT     65361
# define KEY_RIGHT    65363
# define KEY_ESC      65307

# define MOVE_SPEED		0.125
# define ROT_SPEED		0.075
# define FOV		    0.99

typedef struct s_ray
{
    double dir_x;
    double dir_y;
    double delta_x;
    double delta_y;
    double side_x;
    double side_y;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int side;
    double perp_wall_dist;
    int line_height;
    int draw_start;
    int draw_end;
} t_ray;


typedef struct s_player
{
    double x;          // Position du joueur sur l'axe X
    double y;          // Position du joueur sur l'axe Y
    double dir_x;          // Direction du regard (axe X)
    double dir_y;          // Direction du regard (axe Y)
    double plane_x;        // Plan caméra (axe X)
    double plane_y;        // Plan caméra (axe Y)
    double move_speed;     // Vitesse de déplacement
    double rot_speed;      // Vitesse de rotation
    int move_forward;      // Flag pour avancer
    int move_backward;     // Flag pour reculer
    int move_left;         // Flag pour aller à gauche
    int move_right;        // Flag pour aller à droite
    int rotate_left;       // Flag pour tourner à gauche
    int rotate_right;      // Flag pour tourner à droite
} t_player;

typedef struct s_texture
{
    void    *img_ptr;   // Pointeur vers l'image de la texture
    char    *data;      // Données de la texture
    int     width;      // Largeur de la texture
    int     height;     // Hauteur de la texture
    int     bpp;        // Bits par pixel
    int     line;       // Taille d'une ligne en octets
    int     endian;     // Endianness (0 ou 1)
	char	*pix;
    char    *path;
	double	pos;
	int		x;
	int		y;
} t_texture;

typedef struct s_img
{
    void    *img_ptr;   // Pointeur vers l'image
    char    *data;      // Données de l'image
    int     bpp;        // Bits par pixel
    int     size_line;  // Taille d'une ligne en octets
    int     endian;     // Endianness (0 ou 1)
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	t_img		img;
	int			ceiling_color;
	int			floor_color;
	t_texture	textures[4];
}	t_game;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		player;
	char	**map;
    char    **map_copy;
	char	*start_map;
	int		player_x;
	int		player_y;
}	t_data;

int		init_game(t_game *game);
void	init_player(t_game *game);
void	load_textures(t_game *game);

void	handle_events(t_game *game);
int		render_frame(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	update_player_position(t_game *game);
int		close_window(t_game *game);

void	    put_pixel_to_image(t_img *img, int x, int y, int color);
void	    render_ceiling_and_floor(t_game *game);
t_texture	*define_wall_texture(t_game *game, t_ray *ray);

//INIT FUNCTIONS
void	init_data(t_data *data);
int		init_map(t_data *data);
void	init_end_parsing(t_game *game, t_data *data);

//FREE FUNCTIONS
void	free_data(t_data *data);
void	free_array(char **array);

//PARSING FUNCTIONS
int		check_if_dir(char *file);
int		check_argc(int argc);
int		check_file_end(char *str);
int		check_t_path(char *str);
int		get_rgb_value(char *str);
int		check_map(t_data *data, char *file);
int		check_player(t_data *data, char **map);
int		get_map(t_data *data, char *file);
int		check_last_elem(char *file);
int		check_copy(t_data *data);
int		check_walls(char **copy, int i, int j, int row_count);

int		check_textures(t_data *data, char *file);
int		check_rbg(t_data *data, char *file);
int		check_all(int argc, char **argv, t_data *data);
int		last_check(int argc, char **argv, t_game *game);

//PROTECTED FUNCTIONS
int		protected_open(char *str);
char	**copy_map(char **map);
char	*protected_trim(char *str);
void	*get_rgb(char **array, int *nbr);

//PRINT EVERYTHING
void	print_data(t_data *data);
void    print_map(char **map);

#endif
