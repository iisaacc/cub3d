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