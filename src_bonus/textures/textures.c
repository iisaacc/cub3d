/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 12:31:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

//Hay algo que falla al traducir el rgb a bits (preguntar en 42)
int	ft_load_floor_sky(t_cub *cub)
{
	cub->tx->f_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->f_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->f_img, cub->tx->f_rgb[0],
		cub->tx->f_rgb[1], cub->tx->f_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->f_img, 0, HEIGHT / 2) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	cub->tx->c_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->c_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->c_img, cub->tx->c_rgb[0],
		cub->tx->c_rgb[1], cub->tx->c_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->c_img, 0, 0) < 0)
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

	tx = mlx_load_png(cub->tx->no_pth);
	if (!tx)
		return (ft_error_msg("Error loading NO texture", NULL), -1);
	cub->tx->no_tx = tx;
	tx = mlx_load_png(cub->tx->so_pth);
	if (!tx)
		return (ft_error_msg("Error loading SO texture", NULL), -1);
	cub->tx->so_tx = tx;
	tx = mlx_load_png(cub->tx->we_pth);
	if (!tx)
		return (ft_error_msg("Error loading WE texture", NULL), -1);
	cub->tx->we_tx = tx;
	tx = mlx_load_png(cub->tx->ea_pth);
	if (!tx)
		return (ft_error_msg("Error loading EA texture", NULL), -1);
	cub->tx->ea_tx = tx;
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
