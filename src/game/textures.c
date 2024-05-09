/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/05/09 12:43:11 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <string.h>


int	ft_load_textures(t_cub *cub)
{
	cub->tx->taux = mlx_load_png("./textures/teste.png");
	if (!cub->tx->taux)
		return (ft_error_msg("Error loading texture", NULL), -1);
	cub->tx->iaux = mlx_texture_to_image(cub->mlx, cub->tx->taux);
	if (!cub->tx->iaux)
		return (ft_error_msg("Error loading texture", NULL), -1);
	// cub->tx->iaux = mlx_new_image(cub->mlx, 512, 512);
	// memset(cub->tx->iaux->pixels, 255, cub->tx->iaux->width * cub->tx->iaux->height * sizeof(int32_t));
	// if (mlx_image_to_window(cub->mlx, cub->tx->iaux, 0, 0) < 0)
	// 	return (ft_error_msg("Error loading texture", NULL), -1);
	return (0);
}