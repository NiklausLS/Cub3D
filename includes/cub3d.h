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
# include "../src/minilibx/minilibx_linux/mlx.h"
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
    void	*mlx;
	void	*window;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		player;
	char	**map;
    char    *start_map;
}	t_data;

int		init_game(t_game *game);
void	handle_events(t_game *game);
int		render_frame(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(t_game *game);

//INIT FUNCTIONS
void	init_data(t_data *data);
int		init_map(t_data *data);

//FREE FUNCTIONS
void	free_data(t_data *data);
void	free_array(char **array);

//PARSING FUNCTIONS
int		check_if_dir(char *file);
int		check_argc(int argc);
int		check_file_end(char *str);
int		check_elements(char *file);
//int	check_player(char *file);
int		check_map(t_data *data, char *file);
int		get_map(t_data *data, char *file);

int		check_textures(t_data *data, char *file);
int		check_rbg(t_data *data, char *file);
int		check_all(int argc, char **argv, t_data *data);
int     last_check(int argc, char **argv);

//PROTECTED FUNCTIONS
int		protected_open(char *str);

//PRINT EVERYTHING
void	print_data(t_data *data);

#endif
