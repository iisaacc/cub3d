/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:46:31 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 13:16:39 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------------   LIBS   ---------------------------------*/
// Global
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>

/*--------------------------------   MACROS   --------------------------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	64
# endif

# define PI				3.141592653589793238462643383
# define WIDTH			1280
# define HEIGHT			720
# define WID			640
# define FOV			1.5707963267948966
# define MOVE_SPEED		0.0625
# define ROTATION_SPEED	0.05
# define LINE_LENGTH	10
# define MAP_SIZE		16
# define MAP_CENTER		80
# define SIZE			32
# define BLACK			0x000000FF
# define WHITE			0xFFFFFFFF
# define RED			0xFF0000FF

typedef struct s_tx
{
	char			*no_pth;
	char			*so_pth;
	char			*we_pth;
	char			*ea_pth;
	uint8_t			f_rgb[3];
	uint8_t			c_rgb[3];
	mlx_image_t		*f_img;
	mlx_image_t		*c_img;
	mlx_image_t		*p_img;
	mlx_texture_t	*no_tx;
	mlx_texture_t	*so_tx;
	mlx_texture_t	*we_tx;
	mlx_texture_t	*ea_tx;
}	t_tx;

typedef struct s_player
{
	int				initial_pov;
	double			p_x;
	double			p_y;
	double			p_a;
	double			p_dx;
	double			p_dy;
}	t_player;

typedef struct s_ray
{
	double			angle;
	double			x_cross[2];
	double			y_cross[2];
	double			hit[2];
	mlx_image_t		*img;
}	t_ray;

typedef struct s_wall
{
	int				heigth;
	int				y;
}	t_wall;

typedef struct s_map
{
	char		**map;
	mlx_image_t	*map_img;
}	t_map;

typedef struct s_cub
{
	t_tx			*tx;
	t_ray			*ray;
	char			**split_input;
	mlx_t			*mlx;
	mlx_image_t		*arrow;
	t_player		*player;
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

/*-------------------------------   FUNCTIONS   ------------------------------*/
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
void	draw_player_direction(t_cub *cub);
void	ft_mlx_draw_line(mlx_image_t *image, int x1, int y1);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_draw_walls(t_cub *cub, double horiz, double dist, int i);
int		ft_load_map(t_cub *cub);
int		ft_refresh_map(t_cub *cub);
void	ft_refresh_ray_img(t_cub *cub);
void	ft_refresh_map_img(t_cub *cub);
void	ft_set_color(mlx_image_t *img, uint8_t r, uint8_t g, uint8_t b);
int		ft_load_player(t_cub *cub);
void	ft_draw_player_direction(t_cub *cub);

//-------------------MOVEMENTS-----------------------
void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub);
void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub);

//---------------------HOOKS-------------------------
void	ft_hooks(mlx_key_data_t keydata, void *param);

#endif