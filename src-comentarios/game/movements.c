/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:47:11 by isporras          #+#    #+#             */
/*   Updated: 2024/06/28 15:01:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		cub->player->p_a -= ROTATION_SPEED;
		if (cub->player->p_a < 0)
			cub->player->p_a += 2 * PI;
		cub->player->p_dx = cos(cub->player->p_a) * MOVE_SPEED;
		cub->player->p_dy = sin(cub->player->p_a) * MOVE_SPEED;
	}
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		cub->player->p_a += ROTATION_SPEED;
		if (cub->player->p_a > 2 * PI)
			cub->player->p_a -= 2 * PI;
		cub->player->p_dx = cos(cub->player->p_a) * MOVE_SPEED;
		cub->player->p_dy = sin(cub->player->p_a) * MOVE_SPEED;
	}
}

void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		if (ft_is_wall(cub->player->p_x + cub->player->p_dx
				, cub->player->p_y - cub->player->p_dy, cub))
			return ;
		cub->player->p_x += cub->player->p_dx;
		cub->player->p_y -= cub->player->p_dy;
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		if (ft_is_wall(cub->player->p_x - cub->player->p_dx
				, cub->player->p_y + cub->player->p_dy, cub))
			return ;
		cub->player->p_x -= cub->player->p_dx;
		cub->player->p_y += cub->player->p_dy;
	}
}

void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		if (ft_is_wall(cub->player->p_x - cub->player->p_dy
				, cub->player->p_y - cub->player->p_dx, cub))
			return ;
		cub->player->p_x -= cub->player->p_dy;
		cub->player->p_y -= cub->player->p_dx;
	}
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		if (ft_is_wall(cub->player->p_x + cub->player->p_dy
				, cub->player->p_y + cub->player->p_dx, cub))
			return ;
		cub->player->p_x += cub->player->p_dy;
		cub->player->p_y += cub->player->p_dx;
	}
}
