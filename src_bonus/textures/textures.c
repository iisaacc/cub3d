/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/07/03 17:05:44 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

//Hay algo que falla al traducir el rgb a bits (preguntar en 42)
int	ft_load_floor_sky(t_cub *cub)
{
	cub->tx->F_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->F_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->F_img, cub->tx->F_rgb[0],
		cub->tx->F_rgb[1], cub->tx->F_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->F_img, 0, HEIGHT / 2) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	cub->tx->C_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->C_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->C_img, cub->tx->C_rgb[0],
		cub->tx->C_rgb[1], cub->tx->C_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->C_img, 0, 0) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	return (0);
}

int	ft_load_map(t_cub *cub)
{
	cub->map->map_img = mlx_new_image(cub->mlx, MAP_SIZE * 30, MAP_SIZE * 30);
	if (!cub->map->map_img)
		return (ft_error_msg("Error loading map texture", NULL), -1);
	mlx_image_to_window(cub->mlx, cub->map->map_img, 0, 0);
	if (ft_refresh_map(cub) == 1)
		return (EXIT_FAILURE);
	return (0);
}

int	ft_load_wall_textures(t_cub *cub)
{
	mlx_texture_t	*tx;

	tx = mlx_load_png(cub->tx->NO_pth);
	if (!tx)
		return (ft_error_msg("Error loading NO texture", NULL), -1);
	cub->tx->NO_tx = tx;
	tx = mlx_load_png(cub->tx->SO_pth);
	if (!tx)
		return (ft_error_msg("Error loading SO texture", NULL), -1);
	cub->tx->SO_tx = tx;
	tx = mlx_load_png(cub->tx->WE_pth);
	if (!tx)
		return (ft_error_msg("Error loading WE texture", NULL), -1);
	cub->tx->WE_tx = tx;
	tx = mlx_load_png(cub->tx->EA_pth);
	if (!tx)
		return (ft_error_msg("Error loading EA texture", NULL), -1);
	cub->tx->EA_tx = tx;
	return (0);
}

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_map(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_player(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_wall_textures(cub) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
