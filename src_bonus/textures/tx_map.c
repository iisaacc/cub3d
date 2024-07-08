/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:55:46 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:30:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	ft_load_player(t_cub *cub)
{
	if (cub->tx->p_img)
		mlx_delete_image(cub->mlx, cub->tx->p_img);
	cub->tx->p_img = mlx_new_image(cub->mlx, 5, 5);
	if (!cub->tx->p_img)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_set_color(cub->tx->p_img, 255, 0, 0);
	if (mlx_image_to_window(cub->mlx, cub->tx->p_img,
			MAP_CENTER - 2, MAP_CENTER - 2) < 0)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_draw_player_direction(cub);
	return (0);
}

void	ft_put_pixel_map_aux(t_cub *cub, int x, int y, int *k)
{
	double	px_x;
	double	px_y;
	double	radio;

	radio = 5 * MAP_SIZE;
	px_x = (x - cub->player->p_x + 5) * MAP_SIZE + k[1];
	px_y = (y - cub->player->p_y + 5) * MAP_SIZE + k[0];
	if (((px_x - 5 * MAP_SIZE) * (px_x - 5 * MAP_SIZE)
			+ (px_y - 5 * MAP_SIZE)
			* (px_y - 5 * MAP_SIZE)) <= radio * radio)
	{
		if (cub->map->map[y][x] == '1')
			mlx_put_pixel(cub->map->map_img, px_x, px_y, BLACK);
		else if (cub->map->map[y][x] == '0'
				|| cub->map->map[y][x] == 'E'
				|| cub->map->map[y][x] == 'S'
				|| cub->map->map[y][x] == 'N'
				|| cub->map->map[y][x] == 'W')
			mlx_put_pixel(cub->map->map_img, px_x, px_y, WHITE);
	}
}

void	ft_put_pixel_map(t_cub *cub, int x, int y)
{
	int	k[2];

	k[0] = 0;
	while (k[0] < MAP_SIZE)
	{
		k[1] = 0;
		while (k[1] < MAP_SIZE)
		{
			ft_put_pixel_map_aux(cub, x, y, k);
			k[1]++;
		}
		k[0]++;
	}
}

void	ft_draw_contour(t_cub *cub)
{
	int	x;
	int	y;
	int	center;
	int	r;
	int	d;

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
					mlx_put_pixel(cub->map->map_img, x, y, RED);
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
		while (cub->map->map[y][x]
			&& cub->player->p_y - 5 <= y && y <= cub->player->p_y + 5)
		{
			if (cub->player->p_x - 5 <= x && x <= cub->player->p_x + 5)
				ft_put_pixel_map(cub, x, y);
			x++;
		}
		y++;
	}
	ft_draw_contour(cub);
	ft_load_player(cub);
	return (0);
}
