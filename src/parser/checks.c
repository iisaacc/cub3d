#include "../../includes/cub3d.h"

// int	ft_valid_paths(char **split_input)
// {
// 	int	i;

// 	i = 0;
// 	while (split_input[i])
// 	{
// 		if (ft_strncmp(split_input[i], "NO ", 3) == 0 ||
// 			ft_strncmp(split_input[i], "SO ", 3) == 0 ||
// 			ft_strncmp(split_input[i], "WE ", 3) == 0 ||
// 			ft_strncmp(split_input[i], "EA ", 3) == 0)
// 		{
// 			if (read/open) //hacer open o read para ver si la ruta es valida
// 				return (ft_error_msg("Invalid path: ", split_input[i]), 1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	ft_valid_rgb(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		if (ft_strncmp(&split_input[i][j], "F ", 2) == 0 ||
			ft_strncmp(&split_input[i][j], "C ", 2) == 0)
			{
				j += 2;
				while (split_input[i][j] == ' ')
					j++;
				while (split_input[i][j] && split_input[i][j] != '\n')
				{
					if (split_input[i][j] != ','
						&& (split_input[i][j] < '0' || split_input[i][j] > '9'))
						return (ft_error_msg("Invalid RGB value: ", split_input[i]), 1);
					j++;
				}
			}
		i++;
	}
	return (0);
}

int	ft_valid_elements(char **split_input)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (split_input[i])
	{
		if (ft_strncmp(split_input[i], "NO ", 3) == 0 ||
			ft_strncmp(split_input[i], "SO ", 3) == 0 ||
			ft_strncmp(split_input[i], "WE ", 3) == 0 ||
			ft_strncmp(split_input[i], "EA ", 3) == 0 ||
			ft_strncmp(split_input[i], "F ", 2) == 0 ||
			ft_strncmp(split_input[i], "C ", 2) == 0 )
			count++;
		else if (split_input[i][0] != '\n' && count != 6)
			return (ft_error_msg("Strange element before textures definitions: ", split_input[i]), 1);
		i++;
	}
	return (0);
}

int	ft_checks(t_cub *cub)
{

	if (ft_valid_elements(cub->split_input) == 1)
		return (1);
	// if (ft_valid_paths(cub->split_input) == 1) //Por hacer
	// 	return (1);
	if (ft_valid_rgb(cub->split_input) == 1)
		return (1);
	cub->map = ft_get_map(cub->split_input);
	if (ft_map_checks(cub->map) == 1)
		return (1);
	printf("map: \n");
	ft_print_split(cub->map);
	return (0);
}