#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./MLX42/include/MLX42/MLX42.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#define WIDTH 1280
#define HEIGHT 720

//Guarda los datos sobre las texturas
typedef struct s_tx
{
	char	*NO_pth;
	char	*SO_pth;
	char	*WE_pth;
	char	*EA_pth;
	int		F_rgb[3];
	int		C_rgb[3];
}	t_tx;

//Guarda los datos principales del juego
typedef struct s_cub
{
	t_tx			tx;
	char			**map;
	char			**split_input;
	mlx_t			*mlx;
	mlx_image_t*	image;
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
t_tx	ft_textures(t_cub *cub);
//--------------------GAME----------------------------
int		ft_game_loop(t_cub *cub);

#endif