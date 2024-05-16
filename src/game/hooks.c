/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:41:20 by isporras          #+#    #+#             */
/*   Updated: 2024/05/13 15:19:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_turn_camera(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		cub->player->p_a -= 0.2;
		if (cub->player->p_a < 0)
			cub->player->p_a += 2 * PI;
		cub->player->p_dx = cos(cub->player->p_a) * MOVE_SPEED;
		cub->player->p_dy = sin(cub->player->p_a) * MOVE_SPEED;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		cub->player->p_a += 0.1;
		if (cub->player->p_a > 2 * PI)
			cub->player->p_a -= 2 * PI;
		cub->player->p_dx = cos(cub->player->p_a) * MOVE_SPEED;
		cub->player->p_dy = sin(cub->player->p_a) * MOVE_SPEED;
	}
	if (fabs(cub->player->p_dx) < 0.001)
		cub->player->p_dx = 0;
	if (fabs(cub->player->p_dy) < 0.001)
		cub->player->p_dy = 0;
	printf("p_a: %f\n", cub->player->p_a);
}

void	ft_move_up_down(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		cub->tx->P_img->instances->x += cub->player->p_dx;
		cub->tx->P_img->instances->y -= cub->player->p_dy;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		cub->tx->P_img->instances->x -= cub->player->p_dx;
		cub->tx->P_img->instances->y += cub->player->p_dy;
	}
}

void	ft_move_left_right(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		cub->tx->P_img->instances->x -= cub->player->p_dy;
		cub->tx->P_img->instances->y -= cub->player->p_dx;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		cub->tx->P_img->instances->x += cub->player->p_dy;
		cub->tx->P_img->instances->y += cub->player->p_dx;
	}
}

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	//cub->map[cub->pos[0]][cub->pos[1]] = '0';//convierte la posicion actual en 0
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S ) && keydata.action == MLX_PRESS)
		ft_move_up_down(keydata, cub);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D) && keydata.action == MLX_PRESS)
		ft_move_left_right(keydata, cub);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		ft_turn_camera(keydata, cub);
	printf("x: %d\n", cub->tx->P_img->instances->x);
	printf("y: %d\n", cub->tx->P_img->instances->y);
	printf("p_dx: %f\n", cub->player->p_dx);
	printf("p_dy: %f\n", cub->player->p_dy);
}

void	ft_close_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	mlx_close_window(cub->mlx);
	mlx_delete_image(cub->mlx, cub->tx->F_img);
	mlx_delete_image(cub->mlx, cub->tx->C_img);
	mlx_delete_image(cub->mlx, cub->tx->P_img);
	if (cub->tx->NO_pth)
		free(cub->tx->NO_pth);
	if (cub->tx->SO_pth)
		free(cub->tx->SO_pth);
	if (cub->tx->WE_pth)
		free(cub->tx->WE_pth);
	if (cub->tx->EA_pth)
		free(cub->tx->EA_pth);
	free(cub->tx);
	free(cub->player);
	mlx_terminate(cub->mlx);
	exit(EXIT_SUCCESS);
}

// int	key_hooks()
// {
	
// }

/* void	ft_hooks(t_cub *cub)
{
	mlx_close_hook(cub->mlx, ft_close_window, cub);
} */