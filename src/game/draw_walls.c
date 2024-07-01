/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:09:16 by isporras          #+#    #+#             */
/*   Updated: 2024/06/28 17:43:45 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_render_texture()
{
	
}

void	ft_select_texture(t_cub *cub, double horiz, int y, int i)
{
	if (i == 0)
	{
		if (cub->ray->angle > PI / 2 && cub->ray->angle < (3 * PI) / 2)
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_rgba(100, 255, 100, 255));//Este
		else
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_rgba(255, 255, 100, 255));//Oeste
	}
	else
	{
		if (cub->ray->angle > 0 && cub->ray->angle < PI)
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_rgba(100, 255, 255, 255));//Norte
		else
			mlx_put_pixel(cub->ray->img, horiz, y, ft_get_rgba(255, 100, 100, 255));//Sur
	}
}

void	ft_draw_walls(t_cub *cub, double horiz, double dist, int i)
{
	int	y;
	int	heigth;
	int	end;

	heigth = HEIGHT / dist;
	if (heigth > HEIGHT)
		heigth = HEIGHT;
	y = (HEIGHT / 2) - (heigth / 2);
	end = (HEIGHT / 2) + (heigth / 2);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (y >= 0 && y < HEIGHT && y <= end)
		ft_select_texture(cub, horiz, y++, i);
}
