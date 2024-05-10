/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/05/10 16:04:57 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <string.h>

// int	ft_load_floor_sky(t_cub *cub)
// {
// 	//Imprimir cielo
// 	cub->tx->taux = mlx_load_png("./textures/sky2.png");
// 	if (!cub->tx->taux)
// 		return (ft_error_msg("Error loading sky texture", NULL), -1);
// 	cub->tx->iaux = mlx_texture_to_image(cub->mlx, cub->tx->taux);
// 	if (!cub->tx->iaux)
// 		return (ft_error_msg("Error loading sky texture", NULL), -1);
// 	if (mlx_image_to_window(cub->mlx, cub->tx->iaux, 0, 0) < 0)
// 		return (ft_error_msg("Error loading sky texture", NULL), -1);
// 	//Imprimir suelo
// 	cub->tx->taux = mlx_load_png("./textures/floor.png");
// 	if (!cub->tx->taux)
// 		return (ft_error_msg("Error loading floor texture", NULL), -1);
// 	cub->tx->iaux = mlx_texture_to_image(cub->mlx, cub->tx->taux);
// 	if (!cub->tx->iaux)
// 		return (ft_error_msg("Error loading floor texture", NULL), -1);
// 	if (mlx_image_to_window(cub->mlx, cub->tx->iaux, 0, 360) < 0)
// 		return (ft_error_msg("Error loading floor texture", NULL), -1);
// 	return (0);
// }

int	ft_load_floor_sky(t_cub *cub)
{
	int				color;
	unsigned int	*pixels;
	int				i;
	
	color = (cub->tx->F_rgb[0] << 24) | (cub->tx->F_rgb[1] << 16) | (cub->tx->F_rgb[2] << 8) | 255;
	printf("color: %d\n", color);
	cub->tx->F_img = mlx_new_image(cub->mlx, WIDTH, 360);
	if (cub->tx->F_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	pixels = (unsigned int *)cub->tx->F_img->pixels;
	i = 0;
	while (i < WIDTH * HEIGHT / 2)
		pixels[i++] = color;
	if (mlx_image_to_window(cub->mlx, cub->tx->F_img, 0, 360) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	color = (cub->tx->C_rgb[0] << 24) | (cub->tx->C_rgb[1] << 16) | (cub->tx->C_rgb[2] << 8) | 255;
	cub->tx->C_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->C_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	pixels = (unsigned int *)cub->tx->C_img->pixels;
	i = 0;
	while (i < WIDTH * HEIGHT / 2)
		pixels[i++] = color;
	if (mlx_image_to_window(cub->mlx, cub->tx->C_img, 0, 0) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	return (0);
}

int	ft_load_player(t_cub *cub)
{
	cub->tx->P_img = mlx_new_image(cub->mlx, 32, 32);
	if (cub->tx->P_img == NULL)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_memset(cub->tx->P_img->pixels, 255, cub->tx->P_img->width * cub->tx->P_img->height * sizeof(int32_t));
	if (mlx_image_to_window(cub->mlx, cub->tx->P_img, cub->pos[0], cub->pos[0]) < 0)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	return (0);
}

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_player(cub) == -1)
		return (EXIT_FAILURE);
	ft_putstr_fd("Textures loaded\n", 1);
	return (EXIT_SUCCESS);
}