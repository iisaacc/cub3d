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

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S )
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_up_down(keydata, cub);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_left_right(keydata, cub);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_turn_camera(keydata, cub);
	printf("x: %d\n", cub->tx->P_img->instances->x);
	printf("y: %d\n", cub->tx->P_img->instances->y);
	printf("p_dx: %f\n", cub->player->p_dx);
	printf("p_dy: %f\n", cub->player->p_dy);
	printf("p_a: %f\n", cub->player->p_a);
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
