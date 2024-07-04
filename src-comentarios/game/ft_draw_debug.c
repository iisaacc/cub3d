/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:23:26 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 11:23:26 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_line_loop(mlx_image_t *image, int x1, int y1, t_line line)
{
	while (true)
	{
		mlx_put_pixel(image, line.x0, line.y0, line.color);
		if (line.x0 == x1 && line.y0 == y1)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

void	ft_mlx_draw_line(mlx_image_t *image, int x1, int y1)
{
	t_line	line;

	line.x0 = MAP_CENTER;
	line.y0 = MAP_CENTER;
	line.dx = abs(x1 - line.x0);
	if (line.x0 < x1)
		line.sx = 1;
	else
		line.sx = -1;
	line.dy = -abs(y1 - line.y0);
	if (line.y0 < y1)
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx + line.dy;
	line.e2;
	line.color = ft_get_rgba(255, 0, 0, 255);
	ft_draw_line_loop(image, x1, y1, line);
}

void	draw_ray(t_cub *cub, double x_collision, double y_collision)
{
	double	x_end;
	double	y_end;

	x_end = (x_collision - cub->player->p_x) * MAP_SIZE;
	y_end = (y_collision - cub->player->p_y) * MAP_SIZE;
	ft_cut_ray_circle(&x_end, &y_end);
	ft_mlx_draw_line(cub->map->map_img, x_end + MAP_CENTER, y_end + MAP_CENTER);
}
