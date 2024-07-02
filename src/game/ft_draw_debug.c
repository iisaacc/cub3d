//Archivo que al final borraremos porque estas funciones dibujan los rayos y la dirección en la que mira el jugador que solo nos sirve para debugear

#include "../../includes/cub3d.h"
#include <string.h>

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

void	draw_player_direction(t_cub *cub)
{
	cub->tx->P_img->instances->x = cub->player->p_x * 32;
	cub->tx->P_img->instances->y = cub->player->p_y * 32;
}