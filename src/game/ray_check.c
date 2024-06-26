#include "../../includes/cub3d.h"

int	ft_on_limits(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i] && i <= y)
	{
		if ( i == y)
		{
			j = 0;
			while (cub->map[i][j] && x != j)
				j++;
			if (x != j)
				return (false);
			else
				return (true);
		}
		i++;
	}
	return (false);
}

double  ft_calc_dist(t_cub *cub, double *hit)
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
            return (floor(pos));
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
    if (ft_on_limits(cub, next_x, next_y) && cub->map[next_y][next_x] != '0'
        && cub->map[next_y][next_x] != 'S' && cub->map[next_y][next_x] != 'N'
        && cub->map[next_y][next_x] != 'W' && cub->map[next_y][next_x] != 'E')
        return (1);
    if (!ft_on_limits(cub, next_x, next_y))
        return (1);
    return (0);
}
