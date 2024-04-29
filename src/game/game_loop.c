/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:45:00 by isporras          #+#    #+#             */
/*   Updated: 2024/04/29 15:11:37 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_game_loop(t_cub *cub)
{
	if (!(cub->mlx = mlx_init(WIDTH, HEIGHT, "puerta", true)))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return(EXIT_FAILURE);
	}
	mlx_loop(cub->mlx);
	if (ft_load_textures(cub) == 1)
		return (mlx_terminate(cub->mlx), EXIT_FAILURE);
	mlx_terminate(cub->mlx);
	return(EXIT_SUCCESS);
}
