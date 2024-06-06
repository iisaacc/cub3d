/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:47:18 by isporras          #+#    #+#             */
/*   Updated: 2024/05/17 09:47:18 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
//r_a es el angulo del rayo en el circulo trigonometrico
//c_a es el angulo del rayo traducido a un cuadrante para usarlo en las formulas siguientes
//xd es el cateto horizontal resultante del primer x_crossing
//Dependiendo del cuadrante la forma de calcular c_a, xd y xy cambia

int	ft_on_limits(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i] && i <= y)
	{
		if ( i == y)
		{
			j = 0;
			while (cub->map[i][j] && x != j)
				j++;
			if (x != j)
				return (false);
			else
				return (true);
		}
		i++;
	}
	return (false);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_raycaster_loop(t_cub *cub)
{
	double	angle;
	double	fov;
	double	step;
	double	ray;

	fov = PI / 2;//90
	step = 0.3;
	angle = cub->player->p_a - (fov / 2);
	if (cub->ray)
		mlx_delete_image(cub->mlx, cub->ray);
	cub->ray = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	ft_raycaster(cub, cub->player->p_a);
	// (void)ray;
	// (void)step;
	// (void)angle;
	while (angle <= cub->player->p_a + (fov / 2))
	{
		if (angle < 0)
			ray = angle + 2 * PI;
		else if (angle > 2 * PI)
			ray = angle - 2 * PI;
		else
			ray = angle;
		ft_raycaster(cub, ray);
		angle += step;
	}
}

void draw_ray(t_cub *cub, mlx_image_t *ray, double x_collision, double y_collision)
{
	printf("x_collision: %f\n", x_collision);
	printf("y_collision: %f\n", y_collision);
	ft_mlx_draw_line(ray, cub->player->p_x, cub->player->p_y, x_collision * MAP_SIZE, y_collision * MAP_SIZE, get_rgba(255, 0, 0, 255));
	mlx_image_to_window(cub->mlx, ray, 0, 0);
}

double	ft_raycaster(t_cub *cub, double r_a)
{
	double	c_a;	//angulo del rayo en el cuadrante
	double	xd;		//cateto horizontal
	double	yd;		//cateto vertical
	double	x_first_step;	//primer paso en x_crossing
	double	x_step;			//paso en x_crossing
	double	y_first_step;	//primer paso en y_crossing
	double	y_step;			//paso en y_crossing
	double	x_crossing_x;	//x_crossing
	double	x_crossing_y;	//y_crossing
	double	y_crossing_x;
	double	y_crossing_y;
	double	dist;			//distancia al muro
	
	dist = 0;
	if (r_a > 0 && r_a <= PI / 2) //PRIMER CUADRANTE
	{
		c_a = r_a;
		xd = 1 - ((cub->player->p_x / MAP_SIZE) - floor(cub->player->p_x / MAP_SIZE));//floor devuelve la parte entera de un numero
		yd = (cub->player->p_y / MAP_SIZE) - floor(cub->player->p_y / MAP_SIZE);
	}
	else if (r_a > PI / 2 && r_a <= PI) //SEGUNDO CUADRANTE
	{
		c_a = PI - r_a;
		xd = (cub->player->p_x / MAP_SIZE) - floor(cub->player->p_x / MAP_SIZE);
		yd = (cub->player->p_y / MAP_SIZE) - floor(cub->player->p_y / MAP_SIZE);
	}
	else if (r_a > PI && r_a <=  3 * PI / 2) //TERCER
	{
		c_a = r_a - PI;
		xd = (cub->player->p_x / MAP_SIZE) - floor(cub->player->p_x / MAP_SIZE);
		yd = 1 - ((cub->player->p_y / MAP_SIZE) - floor(cub->player->p_y / MAP_SIZE));
	}
	else if (r_a > 3 * PI / 2 && r_a <= 2 * PI) //CUARTO
	{
		c_a = (2 * PI) - r_a;
		xd = 1 - ((cub->player->p_x / MAP_SIZE) - floor(cub->player->p_x / MAP_SIZE));
		yd = 1 - ((cub->player->p_y / MAP_SIZE) - floor(cub->player->p_y / MAP_SIZE));
	}
	printf("-----------------RAYO-----------------\n");
	printf("p_a: %f\n", cub->player->p_a);
	printf("p_x: %f\n", cub->player->p_x / MAP_SIZE);
	printf("p_y: %f\n", cub->player->p_y / MAP_SIZE);
	printf("r_a: %f\n", r_a);
	printf("c_a: %f\n", c_a);
	printf("xd: %f\n", xd);
	printf("yd: %f\n", yd);
	x_first_step = xd/cos(c_a);
	x_step = 1 / cos(c_a);
	printf("x_first_step: %f\n", x_first_step);
	printf("x_step: %f\n", x_step);

	y_first_step = yd / sin(c_a);
	y_step = 1 / (sin(c_a));
	printf("y_first_step: %f\n", y_first_step);
	printf("y_step: %f\n\n", y_step);
	//Check first x_crossing from player position.
	x_crossing_x = (cub->player->p_x / MAP_SIZE) + x_first_step * cos(c_a);
	x_crossing_y = (cub->player->p_y / MAP_SIZE) - x_first_step * sin(c_a);
	printf("x_crossing_x: %f\n", x_crossing_x);
	printf("x_crossing_y: %f\n\n", x_crossing_y);
	y_crossing_x = (cub->player->p_x / MAP_SIZE) + y_first_step * cos(c_a);
	y_crossing_y = (cub->player->p_y / MAP_SIZE) - y_first_step * sin(c_a);
	//RESOLVER DUDA DE COMO SE CALCULA Y_CROSSING

	printf("y_crossing_x: %f\n", y_crossing_x);
	printf("y_crossing_y: %f\n\n", y_crossing_y);
	while (ft_on_limits(cub, x_crossing_x, x_crossing_y)
		&& !isnan(x_step) && !isinf(x_step)
		&& cub->map[(int)x_crossing_y][(int)x_crossing_x]
		&& (cub->map[(int)x_crossing_y][(int)x_crossing_x] != '1'))
	{
		x_crossing_x += (x_step * cos(c_a));
	 	x_crossing_y += x_step * sin(c_a);
		printf("x_crossing_x: %f\n", x_crossing_x);
		printf("x_crossing_y: %f\n\n", x_crossing_y);
	}
	while (ft_on_limits(cub, y_crossing_x, y_crossing_y)
		&& !isnan(y_step) && !isinf(y_step) && cub->map[(int)y_crossing_y][(int)y_crossing_x]
		&& (cub->map[(int)y_crossing_y][(int)y_crossing_x] != '1'))
	{
		y_crossing_x += y_step * cos(c_a);
		y_crossing_y += y_step * sin(c_a);
		printf("y_crossing_x: %f\n", y_crossing_x);
		printf("y_crossing_y: %f\n\n\n\n", y_crossing_y);
	}
	printf("on_limits Y_CROSSING: %d\n", ft_on_limits(cub, y_crossing_x, y_crossing_y));
	printf("on_limits X_CROSSING: %d\n", ft_on_limits(cub, x_crossing_x, x_crossing_y));
	if (!ft_on_limits(cub, x_crossing_x, x_crossing_y)
		|| isnan(x_step) || isinf(x_step)
		|| sqrt(pow((x_crossing_x - cub->player->p_x / MAP_SIZE), 2) + pow((x_crossing_y - cub->player->p_y / MAP_SIZE), 2))
		> sqrt(pow((y_crossing_x - cub->player->p_x / MAP_SIZE), 2) + pow((y_crossing_y - cub->player->p_y / MAP_SIZE), 2)))
		{
			dist = sqrt(pow((y_crossing_x - cub->player->p_x / MAP_SIZE), 2) + pow((y_crossing_y - cub->player->p_y / MAP_SIZE), 2));
			draw_ray(cub, cub->ray, y_crossing_x, y_crossing_y);
		}
	else
		{
			dist = sqrt(pow((x_crossing_x - cub->player->p_x / MAP_SIZE), 2) + pow((x_crossing_y - cub->player->p_y / MAP_SIZE), 2));
			draw_ray(cub, cub->ray, x_crossing_x, x_crossing_y);
		}
	return (dist);
}