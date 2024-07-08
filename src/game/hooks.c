/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:41:20 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:30:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_up_down(keydata, cub);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_left_right(keydata, cub);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_turn_camera(keydata, cub);
	ft_refresh_ray_img(cub);
	ft_raycaster_loop(cub);
}

void	ft_close_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	mlx_close_window(cub->mlx);
	mlx_delete_image(cub->mlx, cub->tx->f_img);
	mlx_delete_image(cub->mlx, cub->tx->c_img);
	mlx_delete_image(cub->mlx, cub->tx->p_img);
	if (cub->tx->no_pth)
		free(cub->tx->no_pth);
	if (cub->tx->so_pth)
		free(cub->tx->so_pth);
	if (cub->tx->we_pth)
		free(cub->tx->we_pth);
	if (cub->tx->ea_pth)
		free(cub->tx->ea_pth);
	free(cub->tx);
	free(cub->player);
	mlx_terminate(cub->mlx);
	exit(EXIT_SUCCESS);
}
