/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:41:20 by isporras          #+#    #+#             */
/*   Updated: 2024/05/10 12:41:20 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_close_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	mlx_close_window(cub->mlx);
	mlx_delete_image(cub->mlx, cub->tx->F_img);
	mlx_delete_image(cub->mlx, cub->tx->C_img);
	mlx_delete_image(cub->mlx, cub->tx->P_img);
	mlx_terminate(cub->mlx);
	exit(EXIT_SUCCESS);
}

// int	key_hooks()
// {
	
// }

void	ft_hooks(t_cub *cub)
{
	mlx_close_hook(cub->mlx, ft_close_window, cub);
}