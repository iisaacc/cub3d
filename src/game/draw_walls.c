/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:09:16 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:31:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	ft_get_pixel_color(t_cub *cub, mlx_texture_t *tx, int tx_co[2])
{
	int	p;

	p = 4 * tx_co[0] + (4 * tx_co[1] * tx->width);
	if (p + 2 <= tx->height * tx->width * tx->bytes_per_pixel)
	{
		return (ft_get_rgba(tx->pixels[p], tx->pixels[p + 1],
				tx->pixels[p + 2], 255));
	}
	return (0);
}

unsigned long	ft_get_pixel(t_cub *cub, mlx_texture_t *tx)
{
	double	heigth;
	int		tx_coord[2];

	if (floor(cub->ray->hit[0]) == cub->ray->hit[0])
		tx_coord[0] = (cub->ray->hit[1] - floor(cub->ray->hit[1])) * tx->width;
	else if (floor(cub->ray->hit[1]) == cub->ray->hit[1])
		tx_coord[0] = (cub->ray->hit[0] - floor(cub->ray->hit[0])) * tx->width;
	else
		tx_coord[0] = 0;
	heigth = (double)cub->wall->heigth / tx->width;
	tx_coord[1] = cub->wall->y / heigth;
	return (ft_get_pixel_color(cub, tx, tx_coord));
}

void	ft_select_texture(t_cub *cub, double horiz, int y, int i)
{
	mlx_image_t	*img;

	img = cub->ray->img;
	if (i == 0 && y >= 0 && y < HEIGHT)
	{
		if (cub->ray->angle > PI / 2 && cub->ray->angle < (3 * PI) / 2)
			mlx_put_pixel(img, horiz, y, ft_get_pixel(cub, cub->tx->ea_tx));
		else
			mlx_put_pixel(img, horiz, y, ft_get_pixel(cub, cub->tx->we_tx));
	}
	else if (i == 1 && y >= 0 && y < HEIGHT)
	{
		if (cub->ray->angle > 0 && cub->ray->angle < PI)
			mlx_put_pixel(img, horiz, y, ft_get_pixel(cub, cub->tx->no_tx));
		else
			mlx_put_pixel(img, horiz, y, ft_get_pixel(cub, cub->tx->so_tx));
	}
}

void	ft_draw_walls(t_cub *cub, double horiz, double dist, int i)
{
	int	y;
	int	heigth;
	int	end;

	heigth = HEIGHT / dist;
	cub->wall->heigth = heigth;
	y = (HEIGHT / 2) - (heigth / 2);
	end = (HEIGHT / 2) + (heigth / 2);
	cub->wall->y = 0;
	if (y < 0)
	{
		cub->wall->y = -y;
		y = 0;
	}
	while (y <= end)
	{
		if (y < 0 || y >= HEIGHT)
			y++;
		else
			ft_select_texture(cub, horiz, y++, i);
		cub->wall->y++;
	}
}
