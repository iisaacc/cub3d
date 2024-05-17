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
#define WIDTH			1280
#define HEIGHT			720
#define WID				640
#define FOV				PI / 2
#define MOVE_SPEED		5
#define ROTATION_SPEED	0.2


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
	int				p_x;//guarda la posicion del jugador
	int				p_y;
	double			p_a;//angulo de vista
	double			p_dx;//delta x
	double			p_dy;//delta y
}	t_player;

//Guarda los datos principales del juego
typedef struct s_cub
{
	t_tx			*tx;//guarda la estructura de las texturas
	char			**map;//guarda el mapa
	char			**split_input;//guarda el input
	mlx_t			*mlx;//guarda el puntero de mlx
	mlx_image_t		*image;
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

//-------------------TEXTURES-------------------------
int		ft_load_textures(t_cub *cub);

//-------------------MOVEMENTS-----------------------
void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub);

//---------------------HOOKS-------------------------
void	ft_hooks(mlx_key_data_t keydata, void *param);

#endif