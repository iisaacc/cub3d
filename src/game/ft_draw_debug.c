/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:23:26 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:48:49 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_structure(t_cub *cub)
{
	int	i;

	i = 0;
	printf("NO: %s\n", cub->tx->no_pth);
	printf("SO: %s\n", cub->tx->so_pth);
	printf("WE: %s\n", cub->tx->we_pth);
	printf("EA: %s\n", cub->tx->ea_pth);
	printf("F: %d, %d, %d\n", cub->tx->f_rgb[0],
		cub->tx->f_rgb[1], cub->tx->f_rgb[2]);
	printf("C: %d, %d, %d\n", cub->tx->c_rgb[0],
		cub->tx->c_rgb[1], cub->tx->c_rgb[2]);
	printf("Initial point of view: %d\n", cub->player->initial_pov);
	printf("Initial pos: x: %f, y: %f\n", cub->player->p_x, cub->player->p_y);
	printf("Initial angle: %f\n", cub->player->p_a);
	printf("Initial dx: %f\n", cub->player->p_dx);
	printf("Initial dy: %f\n", cub->player->p_dy);
	printf("Map:\n");
	while (cub->map->map[i])
	{
		printf("%s\n", cub->map->map[i]);
		i++;
	}
}

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
	line.color = ft_get_rgba(255, 0, 0, 255);
	ft_draw_line_loop(image, x1, y1, line);
}

void	ft_cut_ray_circle(double *x_end, double *y_end)
{
	double	radius;
	double	distance;
	double	scale;

	radius = MAP_CENTER;
	distance = sqrt((*x_end) * (*x_end) + (*y_end) * (*y_end));
	if (distance > radius)
	{
		scale = radius / distance;
		*x_end *= scale;
		*y_end *= scale;
	}
}
