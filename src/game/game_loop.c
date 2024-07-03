/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:45:00 by isporras          #+#    #+#             */
/*   Updated: 2024/07/03 15:20:09 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Te he movido los hooks al archivo hooks.c :)

int	ft_game_loop(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "puerta", true);
	if (!cub->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	if (ft_load_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_refresh_ray_img(cub);
	ft_refresh_map_img(cub);
	ft_raycaster_loop(cub);
	mlx_key_hook(cub->mlx, &ft_hooks, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return (EXIT_SUCCESS);
}
