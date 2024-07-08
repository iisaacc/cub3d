/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:17:10 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:31:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_delete_textures(t_cub *cub)
{
	if (cub->tx->no_pth)
		free(cub->tx->no_pth);
	if (cub->tx->so_pth)
		free(cub->tx->so_pth);
	if (cub->tx->we_pth)
		free(cub->tx->we_pth);
	if (cub->tx->ea_pth)
		free(cub->tx->ea_pth);
	if (cub->tx->f_img)
		mlx_delete_image(cub->mlx, cub->tx->f_img);
	if (cub->tx->c_img)
		mlx_delete_image(cub->mlx, cub->tx->c_img);
	if (cub->tx->no_tx)
		mlx_delete_texture(cub->tx->no_tx);
	if (cub->tx->so_tx)
		mlx_delete_texture(cub->tx->so_tx);
	if (cub->tx->we_tx)
		mlx_delete_texture(cub->tx->we_tx);
	if (cub->tx->ea_tx)
		mlx_delete_texture(cub->tx->ea_tx);
	free(cub->tx);
}

void	ft_delete(t_cub *cub)
{
	ft_delete_textures(cub);
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	if (cub->map->map)
		ft_free_2d(cub->split_input);
	free(cub->player);
	free(cub->map);
	free(cub->ray);
	free(cub->wall);
}
