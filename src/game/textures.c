/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:38 by isporras          #+#    #+#             */
/*   Updated: 2024/06/26 12:25:16 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <string.h>

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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

//Hay algo que falla al traducir el rgb a bits (preguntar en 42)
int	ft_load_floor_sky(t_cub *cub)
{
	cub->tx->F_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->F_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->F_img, cub->tx->F_rgb[0], cub->tx->F_rgb[1], cub->tx->F_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->F_img, 0, HEIGHT / 2) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	cub->tx->C_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	if (cub->tx->C_img == NULL)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	ft_set_color(cub->tx->C_img, cub->tx->C_rgb[0], cub->tx->C_rgb[1], cub->tx->C_rgb[2]);
	if (mlx_image_to_window(cub->mlx, cub->tx->C_img, 0, 0) < 0)
		return (ft_error_msg("Error loading floor texture", NULL), -1);
	return (0);
}

int	ft_load_player(t_cub *cub)
{
	cub->tx->P_img = mlx_new_image(cub->mlx, 5, 5);
	if (!cub->tx->P_img)
		return (ft_error_msg("Error loading player texture", NULL), -1);
	ft_set_color(cub->tx->P_img, 255, 0, 0);
	if (mlx_image_to_window(cub->mlx, cub->tx->P_img, cub->player->p_x * 32, cub->player->p_y * 32) < 0)// * 32
		return (ft_error_msg("Error loading player texture", NULL), -1);
	return (0);
}
void ft_mlx_draw_line(mlx_image_t* image, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (true)
    {
        mlx_put_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_player_direction(t_cub *cub)
{
	if (cub->arrow)
		mlx_delete_image(cub->mlx , cub->arrow);
	cub->arrow =  mlx_new_image(cub->mlx, WIDTH, HEIGHT);
    int x0 = (cub->player->p_x * 32) + 2;
    int y0 = (cub->player->p_y * 32) + 2;
    int x1 = x0 + cub->player->p_dx * LINE_LENGTH;
    int y1 = y0 - cub->player->p_dy * LINE_LENGTH;
    ft_mlx_draw_line(cub->arrow, x0, y0, x1, y1, 200);
	mlx_image_to_window(cub->mlx, cub->arrow, 0, 0);
}

int	ft_load_minimap(t_cub *cub)
{
	int	x;
	int	y;
	
	cub->tx->m_walls = mlx_new_image(cub->mlx, 8, 8);
	cub->tx->m_empty = mlx_new_image(cub->mlx, 8, 8);
	if (!cub->tx->m_empty || !cub->tx->m_walls)
		return (ft_error_msg("Error loading minimap textures", NULL), -1);
	ft_set_color(cub->tx->m_walls, 0, 255, 0);
	ft_set_color(cub->tx->m_empty, 0, 0, 0);
	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				mlx_image_to_window(cub->mlx, cub->tx->m_walls, x * 8, y * 8);
			else if (cub->map[y][x] == '0' || cub->map[y][x] == ' ' || cub->map[y][x] == 'S'
					|| cub->map[y][x] == 'N' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
				mlx_image_to_window(cub->mlx, cub->tx->m_empty, x * 8, y * 8);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_load_map(t_cub *cub)
{
	int	x;
	int	y;
	mlx_image_t *walls;
	mlx_image_t *empty;

	walls = mlx_new_image(cub->mlx, MAP_SIZE, MAP_SIZE);
	empty = mlx_new_image(cub->mlx, MAP_SIZE, MAP_SIZE);
	if (!walls || !empty)
		return (ft_error_msg("Error loading map textures", NULL), -1);
	ft_set_color(walls, 50, 50, 50);
	ft_set_color(empty, 255, 255, 255);
	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				mlx_image_to_window(cub->mlx, walls, x * MAP_SIZE, y * MAP_SIZE);
			else if (cub->map[y][x] == '0' || cub->map[y][x] == ' ' || cub->map[y][x] == 'S'
					|| cub->map[y][x] == 'N' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
				mlx_image_to_window(cub->mlx, empty, x * MAP_SIZE, y * MAP_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_load_textures(t_cub *cub)
{
	if (ft_load_floor_sky(cub) == -1)
		return (EXIT_FAILURE);
	if (ft_load_map(cub) == -1)
		return (EXIT_FAILURE);
	//if (ft_load_minimap(cub) == -1)
	//	return (EXIT_FAILURE);
	if (ft_load_player(cub) == -1)
		return (EXIT_FAILURE);
	draw_player_direction(cub);
	return (EXIT_SUCCESS);
}