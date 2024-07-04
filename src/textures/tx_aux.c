/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:51:03 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 11:51:03 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	ft_refresh_ray_img(t_cub *cub)
{
	if (cub->ray->img)
		mlx_delete_image(cub->mlx, cub->ray->img);
	cub->ray->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub->mlx, cub->ray->img, 0, 0);
}

void	ft_set_color(mlx_image_t *img, uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	i;
	uint8_t		a;

	a = 255;
	i = 0;
	while (i < img->width * img->height * 4)
	{
		img->pixels[i++] = r;
		img->pixels[i++] = g;
		img->pixels[i++] = b;
		img->pixels[i++] = a;
	}
}

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
