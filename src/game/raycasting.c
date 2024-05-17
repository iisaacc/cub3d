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

#include "../../includes./cub3d.h"
//r_a es el angulo del rayo en el circulo trigonometrico
//c_a es el angulo del rayo traducido a un cuadrante para usarlo en las formulas siguientes
//xd es el cateto horizontal resultante del primer x_crossing
//Dependiendo del cuadrante la forma de calcular c_a, xd y xy cambia

void	ft_draw_rays(t_cub *cub)
{
	double	r_a;
	double	c_a;
	double	xd;
	double	yd;
	double	x_first_step;
	double	x_step;
	double	y_first_step;
	double	y_step;
	
	if (r_a > 0 && r_a <= PI / 2) //PRIMER CUADRANTE
	{
		c_a = r_a;
		xd = 1 - (cub->player->p_x - floor(cub->player->p_x));//floor devuelve la parte entera de un numero
		yd = cub->player->p_y - floor(cub->player->p_y);
	}
	else if (r_a > PI / 2 && r_a <= PI) //SEGUNDO CUADRANTE
	{
		c_a = PI - r_a;
		xd = cub->player->p_x - floor(cub->player->p_x);
		yd = cub->player->p_y - floor(cub->player->p_y);
	}
	else if (r_a > PI && r_a <=  3 * PI / 2) //TERCER
	{
		c_a = r_a - PI;
		xd = cub->player->p_x - floor(cub->player->p_x);
		yd = 1 - (cub->player->p_y - floor(cub->player->p_y));
	}
	else if (r_a > 3 * PI / 2 && r_a <= 2 * PI) //CUARTO
	{
		c_a = (2 * PI) - r_a;
		xd = 1 - (cub->player->p_x - floor(cub->player->p_x));
		yd = 1 - (cub->player->p_y - floor(cub->player->p_y));
	}

	x_first_step = xd/cos(c_a);
	x_step = 1 / cos(c_a);

	y_first_step = yd/sin(c_a);
	y_step = 1 /(sin(c_a));

	//Check first x_crossing from player position.
	x_crossing_x = cub->player->p_x + x_first_step * cos(c_a);
	x_crossing_y = p_y - x_first_step * sin(c_a);
	while (square[x_crossing_y][x_crossing_x] != wall)
	{

	}
}