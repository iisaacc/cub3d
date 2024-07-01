/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:50 by isporras          #+#    #+#             */
/*   Updated: 2024/07/02 17:27:04 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	draw_ray(t_cub *cub, mlx_image_t *ray, double x_collision, double y_collision)
{
	ft_mlx_draw_line(ray, cub->player->p_x * 32, cub->player->p_y * 32, x_collision * MAP_SIZE, y_collision * MAP_SIZE, ft_get_rgba(255, 0, 0, 255));
	mlx_image_to_window(cub->mlx, ray, 0, 0);
}

double	ft_normalize(double angle)
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
	int		horiz;
	double s;
	double dist;

	angle = cub->player->p_a - (FOV / 2);
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	cub->ray->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->ray->angle = cub->player->p_a;
	horiz = WIDTH;
	s = WIDTH / 2;
	dist = horiz - WIDTH / 2 - 0.5;
	angle = cub->player->p_a + asin((dist) / (sqrt(dist * dist + s * s)));
	while (horiz >= 0)
	{
		cub->ray->angle = ft_normalize(angle);
		ft_raycaster(cub, horiz);
		dist = horiz - WIDTH / 2 - 0.5;
		angle = cub->player->p_a - asin((dist) / (sqrt(dist * dist + s * s)));
		horiz--;
	}
}

void	ft_collision_x(t_cub *cub, double *hit_x)
{
	hit_x[0] = cub->player->p_x;
	hit_x[1] = cub->player->p_y;
	while (!ft_is_wall(hit_x[0], hit_x[1], cub))
	{
		if (cub->ray->angle < PI / 2 || cub->ray->angle > (3 * PI) / 2)//Si el jugador mira hacia la derecha comprobamos la parte entera de la casilla + 1 (Para saber cual va a ser su proximo x crossing)
			hit_x[0] = floor(hit_x[0]) + 1;
		else
			hit_x[0] = ceil(hit_x[0]) - 1;//Si el jugador mira hacia la derecha comprobamos la siguiente casilla (en caso de que tenga decimales) - 1
		hit_x[1] = (cub->player->p_x - hit_x[0]) * tan(cub->ray->angle);//Esta fórmula nos permite obtener la y a partir del ángulo del rayo y la coordenada x donde estamos comprobando si colisiona
		hit_x[1] += cub->player->p_y;//Le sumamos la posición en y del jugador
		if (hit_x[0] > 1000 || hit_x[1] > 1000)
			break ;
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
			break ;
	}
	if (hit_y[0] > 1000 || hit_y[1] > 1000)
	{
		hit_y[0] = 1000;
		hit_y[1] = 1000;
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
	{
		if (i == 0)
		{
			if (cub->ray->angle > PI / 2 && cub->ray->angle < (3 * PI) / 2)
				mlx_put_pixel(cub->ray->img, horiz, y++, ft_get_rgba(100, 255, 100, 255));
			else
				mlx_put_pixel(cub->ray->img, horiz, y++, ft_get_rgba(255, 255, 100, 255));
		}
		else
		{
			if (cub->ray->angle > 0 / 2 && cub->ray->angle < PI)
				mlx_put_pixel(cub->ray->img, horiz, y++, ft_get_rgba(100, 255, 255, 255));
			else
				mlx_put_pixel(cub->ray->img, horiz, y++, ft_get_rgba(255, 100, 100, 255));
		}
	}
}

void	ft_raycaster(t_cub *cub, double horiz)
{
	double	x_hit[2];//coordenadas [x][y]
	double	y_hit[2];
	double	x_dist;
	double	y_dist;
	double	anti_fish_eye;

	ft_collision_x(cub, x_hit);
	x_dist = ft_calc_dist(cub, x_hit);
	ft_collision_y(cub, y_hit);
	y_dist = ft_calc_dist(cub, y_hit);
	anti_fish_eye = cos(cub->ray->angle - cub->player->p_a);
	mlx_image_to_window(cub->mlx, cub->ray->img, 0, 0);
	if (x_dist < y_dist)
	{
		cub->ray->hit[0] = x_hit[0];
		cub->ray->hit[1] = x_hit[1];
		ft_draw_walls(cub, horiz, x_dist * anti_fish_eye, 0);
		draw_ray(cub, cub->ray->img, x_hit[0], x_hit[1]);
	}
	else
	{
		cub->ray->hit[0] = y_hit[0];
		cub->ray->hit[1] = y_hit[1];
		ft_draw_walls(cub, horiz, y_dist * anti_fish_eye, 1);
		draw_ray(cub, cub->ray->img, y_hit[0], y_hit[1]);
	}
}
