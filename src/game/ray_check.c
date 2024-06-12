#include "../../includes/cub3d.h"

double  ft_cal_dis(t_cub *cub, double *hit)
{
    double  dist;

    dist = pow(cub->player->p_x - hit[0], 2);
    dist += pow(cub->player->p_y - hit[1], 2);
    return (sqrt(dist));
}

int ft_next(double pos, double p_pos)
{
    if (pos - p_pos < 0)
    {
        if (pos == floor(pos))
            return (floor(pos) - 1);
        else
            return (florr(pos));
    }
    else
        return (floor(pos));
}

int ft_is_wall(double x, double y, t_cub *cub)
{
    int next_x;
    int next_y;

    next_x = ft_next(x, cub->player->p_x);
    next_y = ft_next(y, cub->player->p_y);
    if (cub->map[next_x][next_y] != '0')
        return (1);
    return (0);
}
