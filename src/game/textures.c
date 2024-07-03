/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/07/03 17:05:44 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <string.h>

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_set_color(mlx_image_t *img, uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	i;
	uint8_t		a;

	a = 255;
	i = 0;
	while (i < img->width * img->height * 4)
	{
		img->pixels[i++] = r;
		img->pixels[i++] = g;
		img->pixels[i++] = b;
		img->pixels[i++] = a;
	}
}

//Hay algo que falla al traducir el rgb a bits (preguntar en 42)
int	ft_load_floor_sky(t_cub *cub)
{
	cub->tx->F_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->F_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->F_img, cub->tx->F_rgb[0],
		cub->tx->F_rgb[1], cub->tx->F_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->F_img, 0, HEIGHT / 2) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	cub->tx->C_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->C_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->C_img, cub->tx->C_rgb[0],
		cub->tx->C_rgb[1], cub->tx->C_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->C_img, 0, 0) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	return (0);
}

//Dibuja una flecha con la dirección del jugador
void	ft_draw_player_direction(t_cub *cub)
{
	
	int endX = MAP_CENTER + (int)(cos(-cub->player->p_a) * LINE_LENGTH); // Calcula el punto final usando coseno para x
	int endY = MAP_CENTER + (int)(sin(-cub->player->p_a) * LINE_LENGTH); // Calcula el punto final usando seno para y

	// Dibuja la línea en la imagen del jugador
	ft_mlx_draw_line(cub->map->map_img, MAP_CENTER, MAP_CENTER, endX, endY, ft_get_rgba(255, 0, 0, 255)); // 0xFFFFFF es el color blanco
}

int	ft_load_player(t_cub *cub)
{	
	if (cub->tx->P_img)
		mlx_delete_image(cub->mlx, cub->tx->P_img);
	cub->tx->P_img = mlx_new_image(cub->mlx, 5, 5);
	if (!cub->tx->P_img)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_set_color(cub->tx->P_img, 255, 0, 0);
	if (mlx_image_to_window(cub->mlx, cub->tx->P_img,
			MAP_CENTER - 2, MAP_CENTER - 2) < 0)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_draw_player_direction(cub);
	return (0);
}

void	ft_put_pixel_map(t_cub *cub, int x, int y)
{
	double	i;
	double	j;
	double	radio;
	double	px_x;
	double	px_y;

	radio = 5 * MAP_SIZE;
	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			px_x = (x - cub->player->p_x + 5) * MAP_SIZE + j;
			px_y = (y - cub->player->p_y + 5) * MAP_SIZE + i;
			if (((px_x - 5 * MAP_SIZE) * (px_x - 5 * MAP_SIZE) + (px_y - 5 * MAP_SIZE) * (px_y - 5 * MAP_SIZE)) <= radio * radio)
			{
				if (cub->map->map[y][x] == '1')
					mlx_put_pixel(cub->map->map_img, px_x, px_y, ft_get_rgba(0, 0, 0, 255));
				else if (cub->map->map[y][x] == '0' /* || cub->map->map[y][x] == ' ' */
						|| cub->map->map[y][x] == 'S'
						|| cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'E'
						|| cub->map->map[y][x] == 'W')
					mlx_put_pixel(cub->map->map_img, px_x, px_y, ft_get_rgba(255, 255, 255, 255));
				else
					mlx_put_pixel(cub->map->map_img, px_x, px_y, ft_get_rgba(255, 255, 0, 255));
			}
			j++;
		}
		i++;
	}
}

void	ft_draw_contour(t_cub *cub)
{
	int	x;
	int	y;
	int	center;
	int	r;
	int d;

	center = 5 * MAP_SIZE;
	r = 5 * MAP_SIZE;
	x = center - r - 1;
	while (x <= center + r + 1)
	{
		y = center - r - 1;
		while (y <= center + r + 1)
		{
			d = (x - center) * (x - center) + (y - center) * (y - center);
			if (d <= (r + 2) * (r + 2) && d >= (r - 2) * (r - 2))
			{
				if (x >= 0 && x < MAP_SIZE * 30 && y >= 0 && y < MAP_SIZE * 30)
					mlx_put_pixel(cub->map->map_img, x, y, ft_get_rgba(255, 0, 0, 255));
			}
			y++;
		}
		x++;
	}
}

int	ft_refresh_map(t_cub *cub)
{
	int			x;
	int			y;

	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x] && cub->player->p_y - 5 <= y && y <= cub->player->p_y + 5)
		{
			if (cub->player->p_x - 5 <= x && x <= cub->player->p_x + 5 )
				ft_put_pixel_map(cub, x, y);
			x++;
		}
		y++;
	}
	ft_draw_contour(cub);
	ft_load_player(cub);
	return (0);
}


int	ft_load_map(t_cub *cub)
{
	cub->map->map_img = mlx_new_image(cub->mlx, MAP_SIZE * 30, MAP_SIZE * 30);
	if (!cub->map->map_img)
		return (ft_error_msg("Error loading map texture", NULL), -1);
	mlx_image_to_window(cub->mlx, cub->map->map_img, 0, 0);
	if (ft_refresh_map(cub) == 1)
		return (EXIT_FAILURE);
	return (0);
}

int	ft_load_wall_textures(t_cub *cub)
{
	mlx_texture_t	*tx;

	tx = mlx_load_png(cub->tx->NO_pth);
	if (!tx)
		return (ft_error_msg("Error loading NO texture", NULL), -1);
	cub->tx->NO_tx = tx;
	tx = mlx_load_png(cub->tx->SO_pth);
	if (!tx)
		return (ft_error_msg("Error loading SO texture", NULL), -1);
	cub->tx->SO_tx = tx;
	tx = mlx_load_png(cub->tx->WE_pth);
	if (!tx)
		return (ft_error_msg("Error loading WE texture", NULL), -1);
	cub->tx->WE_tx = tx;
	tx = mlx_load_png(cub->tx->EA_pth);
	if (!tx)
		return (ft_error_msg("Error loading EA texture", NULL), -1);
	cub->tx->EA_tx = tx;
	return (0);
}

void	ft_refresh_ray_img(t_cub *cub)
{
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	cub->ray->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub->mlx, cub->ray->img, 0, 0);
}

void	ft_refresh_map_img(t_cub *cub)
{
	if (cub->map->map_img)
		mlx_delete_image(cub->mlx, cub->map->map_img);
	cub->map->map_img = mlx_new_image(cub->mlx, MAP_SIZE * 30, MAP_SIZE * 30);
	mlx_image_to_window(cub->mlx, cub->map->map_img, 0, 0);
}

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_map(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_player(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_wall_textures(cub) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
