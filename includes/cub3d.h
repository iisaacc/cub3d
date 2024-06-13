#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#define PI				3.141592653589793238462643383
#define WIDTH			1280 * 2
#define HEIGHT			720 * 2
#define WID				640
#define FOV				PI / 2
#define MOVE_SPEED		5 / 32
#define ROTATION_SPEED	0.2
#define LINE_LENGTH		5
#define MAP_SIZE		32


//Guarda los datos sobre las texturas
typedef struct s_tx
{
	char			*NO_pth;
	char			*SO_pth;
	char			*WE_pth;
	char			*EA_pth;
	uint8_t			F_rgb[3];
	uint8_t			C_rgb[3];
	mlx_texture_t	*taux;
	mlx_image_t		*F_img;
	mlx_image_t		*C_img;
	mlx_image_t		*P_img;
	mlx_image_t		*m_walls;
	mlx_image_t		*m_empty;
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
	mlx_image_t		*img;
}t_ray;

//Guarda los datos principales del juego
typedef struct s_cub
{
	t_tx			*tx;//guarda la estructura de las texturas
	t_ray			*ray;//guarda la info del rayo
	char			**map;//guarda el mapa
	char			**split_input;//guarda el input
	mlx_t			*mlx;//guarda el puntero de mlx
	mlx_image_t		*arrow;
	t_player		*player;//guarda los datos del jugador
}	t_cub;

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
void	ft_raycaster(t_cub *cub);
void	ft_raycaster_loop(t_cub *cub);
int		ft_is_wall(double x, double y, t_cub *cub);
double	ft_calc_dist(t_cub *cub, double *hit);

//-------------------TEXTURES-------------------------
int		ft_load_textures(t_cub *cub);
void	draw_player_direction(t_cub *cub);
void	ft_mlx_draw_line(mlx_image_t* image, int x0, int y0, int x1, int y1, int color);
int		ft_get_rgba(int r, int g, int b, int a);

//-------------------MOVEMENTS-----------------------
void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub);

//---------------------HOOKS-------------------------
void	ft_hooks(mlx_key_data_t keydata, void *param);

#endif