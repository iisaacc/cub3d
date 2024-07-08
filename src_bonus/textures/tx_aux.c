/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:51:03 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:30:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

void	ft_draw_player_direction(t_cub *cub)
{
	int	endx;
	int	endy;

	endx = MAP_CENTER + (int)(cos(-cub->player->p_a) * LINE_LENGTH);
	endy = MAP_CENTER + (int)(sin(-cub->player->p_a) * LINE_LENGTH);
	ft_mlx_draw_line(cub->map->map_img, endx, endy);
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

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
