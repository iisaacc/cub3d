/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:50 by isporras          #+#    #+#             */
/*   Updated: 2024/07/03 16:32:57 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	double	s;
	double	dist;

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
	if (x_dist < y_dist)
	{
		cub->ray->hit[0] = x_hit[0];
		cub->ray->hit[1] = x_hit[1];
		ft_draw_walls(cub, horiz, x_dist * anti_fish_eye, 0);
	}
	else
	{
		cub->ray->hit[0] = y_hit[0];
		cub->ray->hit[1] = y_hit[1];
		ft_draw_walls(cub, horiz, y_dist * anti_fish_eye, 1);
	}
}
