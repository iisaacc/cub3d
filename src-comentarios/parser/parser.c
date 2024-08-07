#include "../../includes/cub3d.h"

char	**ft_get_map(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j] == ' ')
				j++;
		if (split_input[i][j] && split_input[i][j] != '\n' &&
			ft_strncmp(&split_input[i][j], "NO ", 3) != 0 &&
			ft_strncmp(split_input[i], "SO ", 3) != 0 &&
			ft_strncmp(split_input[i], "WE ", 3) != 0 &&
			ft_strncmp(split_input[i], "EA ", 3) != 0 &&
			ft_strncmp(split_input[i], "F ", 2) != 0 &&
			ft_strncmp(split_input[i], "C ", 2) != 0)
			return (ft_cut_char(&split_input[i], '\n'), &split_input[i]);
		i++;
	}
	return (ft_error_msg("No map found", NULL), NULL);
}

void	ft_print_structure(t_cub *cub)
{
	int	i;

	i = 0;
	printf("NO: %s\n", cub->tx->no_pth);
	printf("SO: %s\n", cub->tx->so_pth);
	printf("WE: %s\n", cub->tx->we_pth);
	printf("EA: %s\n", cub->tx->ea_pth);
	printf("F: %d, %d, %d\n", cub->tx->f_rgb[0], cub->tx->f_rgb[1], cub->tx->f_rgb[2]);
	printf("C: %d, %d, %d\n", cub->tx->c_rgb[0], cub->tx->c_rgb[1], cub->tx->c_rgb[2]);
	printf("Initial point of view: %d\n", cub->player->initial_pov);
	printf("Initial position: x: %f, y: %f\n", cub->player->p_x, cub->player->p_y);
	printf("Initial angle: %f\n", cub->player->p_a);
	printf("Initial dx: %f\n", cub->player->p_dx);
	printf("Initial dy: %f\n", cub->player->p_dy);
	printf("Map:\n");
	while (cub->map->map[i])
	{
		printf("%s\n", cub->map->map[i]);
		i++;
	}
}

int	ft_get_init_pov(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map->map && cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S' ||
				cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
			{
				cub->player->p_y = y + 0.5;//Posición inicial del jugador
				cub->player->p_x = x + 0.5;
				if (cub->map->map[y][x] == 'N')
					return (0);
				else if (cub->map->map[y][x] == 'E')
					return (1);
				else if (cub->map->map[y][x] == 'S')
					return (2);
				else if (cub->map->map[y][x] == 'W')
					return (3);
			}
			x++;
		}
		y++;
	}
	return (ft_error_msg("No initial point of view found", NULL), -1);
}
void	ft_init_struct(t_cub *cub)
{
	cub->tx = ft_calloc(1, sizeof(t_tx));
	cub->player = ft_calloc(1, sizeof(t_player));
	cub->ray = ft_calloc(1, sizeof(t_ray));
	cub->wall = ft_calloc(1, sizeof(t_wall));
	cub->map = ft_calloc(1, sizeof(t_map));
	cub->ray->img = NULL;
	cub->ray->angle = 0;
	cub->player->p_x = 0;
	cub->player->p_y = 0;
	cub->player->p_a = 0;
	cub->player->initial_pov = 0;
	cub->map->map = NULL;
	cub->split_input = NULL;
	cub->arrow = NULL;
}

void	ft_set_player_angle(t_cub *cub)
{
	if (cub->player->initial_pov == 0)
		cub->player->p_a = PI / 2;
	else if (cub->player->initial_pov == 1)
		cub->player->p_a = 0;
	else if (cub->player->initial_pov == 2)
		cub->player->p_a = 3 * PI / 2;
	else if (cub->player->initial_pov == 3)
		cub->player->p_a = PI;
	cub->player->p_dx = cos(cub->player->p_a) * MOVE_SPEED;
	
	cub->player->p_dy = sin(cub->player->p_a) * MOVE_SPEED;
}

int	ft_parser(char	*file, t_cub *cub)
{
	ft_init_struct(cub);
	cub->split_input = ft_read_and_split(file);
	if (cub->split_input == NULL)
		return (ft_delete(cub), 1);
	if (ft_checks(cub) == 1)
		return (ft_delete(cub), 1);
	cub->player->initial_pov = ft_get_init_pov(cub);
	if (cub->player->initial_pov == -1)
		return (ft_delete(cub), 1);
	ft_set_player_angle(cub);
	ft_parser_textures(cub);
	ft_print_structure(cub);
	//ft_conf_elements(split_input);
	return (0);
}