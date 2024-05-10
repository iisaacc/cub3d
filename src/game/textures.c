/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/05/10 14:11:08 by isporras         ###   ########.fr       */
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
	unsigned int	color;
	uint32_t		i;
	
	color = (cub->tx->F_rgb[0] << 16) | (cub->tx->F_rgb[1] << 8) | cub->tx->F_rgb[2];
	//color = (cub->tx->F_rgb[0] << 24) | (cub->tx->F_rgb[1] << 16) | cub->tx->F_rgb[2] << 8 | 255;
	printf("red %d, green %d, blue %d\n", cub->tx->F_rgb[0], cub->tx->F_rgb[1], cub->tx->F_rgb[2]);
	cub->tx->iaux = mlx_new_image(cub->mlx, WIDTH, 360);
	if (cub->tx->iaux == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	i = 0;
	while (i <  cub->tx->iaux->width * cub->tx->iaux->height * sizeof(int32_t))
		cub->tx->iaux->pixels[i++] = color;
	if (mlx_image_to_window(cub->mlx, cub->tx->iaux, 0, 360) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	return (0);
}

// int	ft_load_player(t_cub *cub)
// {
// 	ft_memset(cub->tx->iaux->pixels, 255, cub->tx->iaux->width * cub->tx->iaux->height * sizeof(int32_t));
// }

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	// if (ft_load_player(cub) == -1)
	// 	return (EXIT_FAILURE);
	ft_putstr_fd("Textures loaded\n", 1);
	return (EXIT_SUCCESS);
}