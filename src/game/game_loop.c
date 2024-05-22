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

//Te he movido los hooks al archivo hooks.c :)

int	ft_game_loop(t_cub *cub)
{
	if (!(cub->mlx = mlx_init(WIDTH, HEIGHT, "puerta", true)))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return(EXIT_FAILURE);
	}
	if (ft_load_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_raycaster_loop(cub);
	mlx_key_hook(cub->mlx, &ft_hooks, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return(EXIT_SUCCESS);
}