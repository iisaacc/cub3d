/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:17:10 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 10:17:10 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_delete_textures(t_cub *cub)
{
	if (cub->tx->NO_pth)
		free(cub->tx->NO_pth);
	if (cub->tx->SO_pth)
		free(cub->tx->SO_pth);
	if (cub->tx->WE_pth)
		free(cub->tx->WE_pth);
	if (cub->tx->EA_pth)
		free(cub->tx->EA_pth);
	if (cub->tx->F_img)
		mlx_delete_image(cub->mlx, cub->tx->F_img);
	if (cub->tx->C_img)
		mlx_delete_image(cub->mlx, cub->tx->C_img);
	if (cub->tx->P_img)
		mlx_delete_image(cub->mlx, cub->tx->P_img);
	if (cub->tx->NO_tx)
		mlx_delete_texture(cub->tx->NO_tx);
	if (cub->tx->SO_tx)
		mlx_delete_texture(cub->tx->SO_tx);
	if (cub->tx->WE_tx)
		mlx_delete_texture(cub->tx->WE_tx);
	if (cub->tx->EA_tx)
		mlx_delete_texture(cub->tx->EA_tx);
	free(cub->tx);
}

void	ft_delete(t_cub *cub)
{
	ft_delete_textures(cub);
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	if (cub->map->map_img)
		mlx_delete_image(cub->mlx, cub->map->map_img);
	if (cub->map->map)
		ft_free_2d(cub->split_input);
	free(cub->player);
	free(cub->map);
	free(cub->ray);
	free(cub->wall);
}
