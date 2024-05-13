/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:45:00 by isporras          #+#    #+#             */
/*   Updated: 2024/05/13 15:31:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub; 

	cub = param;
	cub->map[cub->pos[0]][cub->pos[1]] = '0';//convierte la posicion actual en 0
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
	/* if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_down(cub);//por hacer
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(cub);//por hacer
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(cub);//por hacer
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_right(cub);//por hacer */
}

int	ft_game_loop(t_cub *cub)
{
	if (!(cub->mlx = mlx_init(WIDTH, HEIGHT, "puerta", true)))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return(EXIT_FAILURE);
	}
	if (ft_load_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_key_hook(cub->mlx, &ft_hooks, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return(EXIT_SUCCESS);
}