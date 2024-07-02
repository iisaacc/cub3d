/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/07/01 16:09:26 by isporras         ###   ########.fr       */
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

int	ft_load_player(t_cub *cub)
{
	cub->tx->P_img = mlx_new_image(cub->mlx, 5, 5);
	if (!cub->tx->P_img)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_set_color(cub->tx->P_img, 255, 0, 0);
	if (mlx_image_to_window(cub->mlx, cub->tx->P_img,
			cub->player->p_x * SIZE, cub->player->p_y * SIZE) < 0)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	return (0);
}

int	ft_load_minimap(t_cub *cub)
{
	int	x;
	int	y;

	cub->tx->m_walls = mlx_new_image(cub->mlx, 8, 8);
	cub->tx->m_empty = mlx_new_image(cub->mlx, 8, 8);
	ft_set_color(cub->tx->m_walls, 0, 255, 0);
	ft_set_color(cub->tx->m_empty, 0, 0, 0);
	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == '1')
				mlx_image_to_window(cub->mlx, cub->tx->m_walls, x * 8, y * 8);
			else if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == ' '
					|| cub->map->map[y][x] == 'S'
					|| cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'E'
					|| cub->map->map[y][x] == 'W')
				mlx_image_to_window(cub->mlx, cub->tx->m_empty, x * 8, y * 8);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_load_map(t_cub *cub)
{
	int			x;
	int			y;
	mlx_image_t	*walls;
	mlx_image_t	*empty;

	walls = mlx_new_image(cub->mlx, MAP_SIZE, MAP_SIZE);
	empty = mlx_new_image(cub->mlx, MAP_SIZE, MAP_SIZE);
	if (!walls || !empty)
		return (ft_error_msg("Error loading map textures", NULL), -1);
	ft_set_color(walls, 50, 50, 50);
	ft_set_color(empty, 255, 255, 255);
	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x] && cub->player->p_y - 5 >= y && y <= cub->player->p_y + 5)
		{
			if (cub->player->p_x - 5 >= x && x <= cub->player->p_x + 5 )
			{
				if (cub->map->map[y][x] == '1')
					mlx_image_to_window(cub->mlx, walls, x * MAP_SIZE, y * MAP_SIZE);
				else if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == ' '
						|| cub->map->map[y][x] == 'S'
						|| cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'E'
						|| cub->map->map[y][x] == 'W')
					mlx_image_to_window(cub->mlx, empty, x * MAP_SIZE, y * MAP_SIZE);
			}
			x++;
		}
		y++;
	}
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

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_map(cub) == -1)
		return (EXIT_FAILURE);
	//if (ft_load_minimap(cub) == -1)
	//	return (EXIT_FAILURE);
	if (ft_load_player(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_wall_textures(cub) == -1)
		return (EXIT_FAILURE);
	draw_player_direction(cub);
	return (EXIT_SUCCESS);
}
