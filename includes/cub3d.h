#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#define PI				3.141592653589793238462643383
#define WIDTH			1280
#define HEIGHT			720
#define WID				640
#define FOV				PI / 2
#define MOVE_SPEED		2 / 32
#define ROTATION_SPEED	0.05
#define LINE_LENGTH		10
#define MAP_SIZE		16
#define MAP_CENTER		MAP_SIZE * 5
#define SIZE			32
#define BLACK			0x000000FF
#define WHITE			0xFFFFFFFF
#define RED				0xFF0000FF


//Guarda los datos sobre las texturas
typedef struct s_tx
{
	char			*NO_pth;//Ruta a cada una de las texturas
	char			*SO_pth;
	char			*WE_pth;
	char			*EA_pth;
	uint8_t			F_rgb[3];//Códigos rgb del suelo
	uint8_t			C_rgb[3];//Códigos rgb del cielo
	mlx_image_t		*F_img;//Puntero mlx donde se almacena la imagen del suelo
	mlx_image_t		*C_img;//Puntero mlx donde se almacena la imagen del cielo
	mlx_image_t		*P_img;//Puntero mlx donde se almacena la imagen del jugador
	mlx_texture_t	*NO_tx;//Puntero mlx donde se almacena la imagen de la textura NO
	mlx_texture_t	*SO_tx;//Puntero mlx donde se almacena la imagen de la textura SO
	mlx_texture_t	*WE_tx;//Puntero mlx donde se almacena la imagen de la textura WE
	mlx_texture_t	*EA_tx;//Puntero mlx donde se almacena la imagen de la textura EA
}	t_tx;

typedef struct s_player
{
	int				initial_pov;//guarda el punto de vista inicial [0-N, 1-E, 2-S, 3-W]
	double			p_x;//guarda la posicion del jugador
	double			p_y;
	double			p_a;//angulo de vista
	double			p_dx;//delta x
	double			p_dy;//delta y
}	t_player;

typedef struct s_ray
{
	double			angle;
	double			x_cross[2];
	double			y_cross[2];
	double			hit[2];
	mlx_image_t		*img;
}t_ray;

typedef struct s_wall
{
	int				heigth;
	int				y;
}	t_wall;

typedef struct s_map
{
	char		**map;//guarda el mapa
}	t_map;

//Guarda los datos principales del juego
typedef struct s_cub
{
	t_tx			*tx;//guarda la estructura de las texturas
	t_ray			*ray;//guarda la info del rayo
	char			**split_input;//guarda el input
	mlx_t			*mlx;//guarda el puntero de mlx
	mlx_image_t		*arrow;
	t_player		*player;//guarda los datos del jugador
	t_wall			*wall;
	t_map			*map;
}	t_cub;

typedef struct s_line
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	int		x0;
	int		y0;
	int		color;
}	t_line;


//------------------PARSER--------------------------
int		ft_parser(char	*file, t_cub *cub);
char	*get_next_line(int fd);
void	ft_error_msg(char *s1, char *s2);
char	**ft_read_and_split(char *file);
char	**ft_get_map(char **split_input);
int		ft_checks(t_cub *cub);
int		ft_check_way(char **map);
void	ft_cut_char(char **str, char c);
int		ft_map_checks(char **map);
int		ft_parser_textures(t_cub *cub);
//--------------------GAME----------------------------
int		ft_game_loop(t_cub *cub);
void	ft_raycaster(t_cub *cub, double horiz);
void	ft_raycaster_loop(t_cub *cub);
int		ft_is_wall(double x, double y, t_cub *cub);
double	ft_calc_dist(t_cub *cub, double *hit);
void	ft_delete(t_cub *cub);
void	ft_init_struct(t_cub *cub);

//-------------------TEXTURES-------------------------
int		ft_load_textures(t_cub *cub);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_draw_walls(t_cub *cub, double horiz, double dist, int i);
void	ft_refresh_ray_img(t_cub *cub);
void	ft_set_color(mlx_image_t *img, uint8_t r, uint8_t g, uint8_t b);

//-------------------MOVEMENTS-----------------------
void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub);

//---------------------HOOKS-------------------------
void	ft_hooks(mlx_key_data_t keydata, void *param);

#endif