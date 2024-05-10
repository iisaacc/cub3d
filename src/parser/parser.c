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
	printf("NO: %s\n", cub->tx->NO_pth);
	printf("SO: %s\n", cub->tx->SO_pth);
	printf("WE: %s\n", cub->tx->WE_pth);
	printf("EA: %s\n", cub->tx->EA_pth);
	printf("F: %d, %d, %d\n", cub->tx->F_rgb[0], cub->tx->F_rgb[1], cub->tx->F_rgb[2]);
	printf("C: %d, %d, %d\n", cub->tx->C_rgb[0], cub->tx->C_rgb[1], cub->tx->C_rgb[2]);
	printf("Initial point of view: %d\n", cub->initial_pov);
	printf("Initial position: %d, %d\n", cub->pos[0], cub->pos[1]);
	printf("Map:\n");
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}

int	ft_get_init_pov(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S' ||
				cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				cub->pos[0] = y;//Posición inicial del jugador
				cub->pos[1] = x;
				if (cub->map[y][x] == 'N')
					return (0);
				else if (cub->map[y][x] == 'E')
					return (1);
				else if (cub->map[y][x] == 'S')
					return (2);
				else if (cub->map[y][x] == 'W')
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
	cub->pos[0] = -1;
	cub->pos[1] = -1;
	cub->map = NULL;
	cub->split_input = NULL;
}

int	ft_parser(char	*file, t_cub *cub)
{
	ft_init_struct(cub);
	cub->split_input = ft_read_and_split(file);
	if (cub->split_input == NULL)
		return (1);
	if (ft_checks(cub) == 1)
		return (1);
	cub->initial_pov = ft_get_init_pov(cub);
	ft_parser_textures(cub);
	ft_print_structure(cub);
	//ft_conf_elements(split_input);
	return (0);
}