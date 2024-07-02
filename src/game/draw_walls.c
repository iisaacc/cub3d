/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:09:16 by isporras          #+#    #+#             */
/*   Updated: 2024/07/02 15:59:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	ft_get_pixel_color(t_cub *cub, mlx_texture_t *tx, int tx_coord[2])
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	p;

	//printf("tx_coord[0] = %d\n", tx_coord[0]);
	p = 4 * tx_coord[0] + (4 * tx_coord[1] * tx->width);
	if (p <= tx->height * tx->width * tx->bytes_per_pixel)
	{
		r = tx->pixels[p];
		g = tx->pixels[p + 1];
		b = tx->pixels[p + 2];
		a = tx->pixels[p + 3];
		return (r << 24 | g << 16 | b << 8 | 0xFF);
	}
	return (0);
}

unsigned long	ft_get_pixel(t_cub *cub, mlx_texture_t *tx)
{
	double	heigth;
	int tx_coord[2];

	if (floor(cub->ray->hit[0]) == cub->ray->hit[0])
	{
		tx_coord[0] = (cub->ray->hit[1] - floor(cub->ray->hit[1])) * tx->width;
		//printf("cub->ray->hit[0] = %f\n tx_coord[0] = %d\n", cub->ray->hit[1], tx_coord[0]);
	}
	else if (floor(cub->ray->hit[1]) == cub->ray->hit[1])
	{
		tx_coord[0] = (cub->ray->hit[0] - floor(cub->ray->hit[0])) * tx->width;
		//printf("cub->ray->hit[1] = %f\n tx_coord[0] = %d\n", cub->ray->hit[1], tx_coord[0]);
	}
	else
	{
		//printf("else\n");
		tx_coord[0] = 0;
	}
/* 	printf("--------------------\n");
	printf("cub->wall->height = %d\n", cub->wall->heigth);
	printf("cu->wall->y = %d\n", cub->wall->y);
	printf("tx->height = %d\n", tx->height); */
	heigth = (double)cub->wall->heigth / tx->height;
/* 	printf("heigth = %f\n", heigth); */
	tx_coord[1] = cub->wall->y++ / heigth;
/* 	printf("tx_coord[1] = %d\n", tx_coord[1]); */

	return (ft_get_pixel_color(cub, tx, tx_coord));
}

void	ft_select_texture(t_cub *cub, double horiz, int y, int i)
{
	if (i == 0 && y >= 0 && y < HEIGHT)
	{
		if (cub->ray->angle > PI / 2 && cub->ray->angle < (3 * PI) / 2)
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_pixel(cub, cub->tx->EA_tx));//Este
		else
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_pixel(cub, cub->tx->WE_tx));//Oeste
	}
	else if (i == 1 && y >= 0 && y < HEIGHT)
	{
		if (cub->ray->angle > 0 && cub->ray->angle < PI)
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_pixel(cub, cub->tx->NO_tx));//Norte
		else
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_pixel(cub, cub->tx->SO_tx));//Sur
	}
}

//pixel = [x= 22,5 y = 20] [x = 0,5 y = 0]   

void	ft_draw_walls(t_cub *cub, double horiz, double dist, int i)
{
	int	y;
	int	heigth;
	int	end;

	heigth = HEIGHT / dist;
	cub->wall->heigth = heigth;
	cub->wall->y = 0;
	y = (HEIGHT / 2) - (heigth / 2);
	end = (HEIGHT / 2) + (heigth / 2);
	if (end >= HEIGHT)
		end = HEIGHT;
	while (y <= end)
		ft_select_texture(cub, horiz, y++, i);
}
