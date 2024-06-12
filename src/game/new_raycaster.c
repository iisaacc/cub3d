/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:50 by isporras          #+#    #+#             */
/*   Updated: 2024/06/12 18:07:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void draw_ray(t_cub *cub, mlx_image_t *ray, double x_collision, double y_collision)
{
	printf("x_collision: %f\n", x_collision);
	printf("y_collision: %f\n", y_collision);
	ft_mlx_draw_line(ray, cub->player->p_x * 32, cub->player->p_y * 32, x_collision * MAP_SIZE, y_collision * MAP_SIZE, get_rgba(255, 0, 0, 255));
	mlx_image_to_window(cub->mlx, ray, 0, 0);
}

double  ft_normalize(double angle)
{
	double	normalize;

	if (angle < 0)
		normalize = angle + (2 * PI);
	else if (angle > (2 * PI))
		normalize = angle - (2 * PI);
	else
		normalize = angle;
	return (normalize);
}

void	ft_raycaster_loop(t_cub *cub)
{
	double	angle;
	double	fov;
	double	step;

	fov = PI / 2;//90
	step = 0.05;
	angle = cub->player->p_a - (fov / 2);
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	cub->ray->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->ray->angle = cub->player->p_a;
	ft_raycaster(cub);
	while (angle <= cub->player->p_a + (fov / 2))
	{
		cub->ray->angle = ft_normalize(angle);
		ft_raycaster(cub);
		angle += step;
	}
}

void	ft_collision_x(t_cub *cub, double *hit_x)
{
	hit_x[0] = cub->player->p_x;
	hit_x[1] = cub->player->p_y;
	printf("is_wall: %d\n", ft_is_wall(hit_x[0], hit_x[1], cub));
	while (!ft_is_wall(hit_x[0], hit_x[1], cub))
	{
		if (cub->ray->angle < PI / 2 || cub->ray->angle > (3 * PI) / 2)
			hit_x[0] = floor(hit_x[0]) + 1;
		else
			hit_x[0] = ceil(hit_x[0]) - 1;
		hit_x[1] = (cub->player->p_x - hit_x[0]) * tan(cub->ray->angle);
		hit_x[1] += cub->player->p_y;
		if (hit_x[0] > 1000 || hit_x[1] > 1000)
			break;
	}
	if (hit_x[0] > 1000 || hit_x[1] > 1000)
	{
		hit_x[0] = 1000;
		hit_x[1] = 1000;
	}
}

void	ft_collision_y(t_cub *cub, double *hit_y)
{
	hit_y[0] = cub->player->p_x;
	hit_y[1] = cub->player->p_y;
	while (!ft_is_wall(hit_y[0], hit_y[1], cub))
	{
		if (cub->ray->angle < PI)
			hit_y[1] = ceil(hit_y[1]) - 1;
		else
			hit_y[1] = floor(hit_y[1]) + 1;
		hit_y[0] = (cub->player->p_y - hit_y[1]) / tan(cub->ray->angle);
		hit_y[0] += cub->player->p_x;
		if (hit_y[0] > 1000 || hit_y[1] > 1000)
			break;
	}
	if (hit_y[0] > 1000 || hit_y[1] > 1000)
	{
		hit_y[0] = 1000;
		hit_y[1] = 1000;
	}
}

void	ft_raycaster(t_cub *cub)
{
	double	x_hit[2];//coordenadas [x][y]
	double	y_hit[2];
	double	x_dist;
	double	y_dist;

	ft_collision_x(cub, x_hit);
	x_dist = ft_calc_dist(cub, x_hit);
	printf("x_dist: %f\n", x_dist);
	ft_collision_y(cub, y_hit);
	y_dist = ft_calc_dist(cub, y_hit);
	printf("y_dist: %f\n", y_dist);
	if (x_dist < y_dist)
		draw_ray(cub, cub->ray->img, x_hit[0], x_hit[1]);
	else
		draw_ray(cub, cub->ray->img, y_hit[0], y_hit[1]);
}