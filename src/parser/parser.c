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

void	ft_print_textures(t_tx tx)
{
	printf("NO: %s\n", tx.NO_pth);
	printf("SO: %s\n", tx.SO_pth);
	printf("WE: %s\n", tx.WE_pth);
	printf("EA: %s\n", tx.EA_pth);
	printf("F: %d,%d,%d\n", tx.F_rgb[0], tx.F_rgb[1], tx.F_rgb[2]);
	printf("C: %d,%d,%d\n", tx.C_rgb[0], tx.C_rgb[1], tx.C_rgb[2]);
}

int	ft_parser(char	*file, t_cub *cub)
{

	cub->split_input = ft_read_and_split(file);
	if (cub->split_input == NULL)
		return (1);
	if (ft_checks(cub) == 1)
		return (1);
	cub->tx = ft_textures(cub);
	ft_print_textures(cub->tx);
	//ft_conf_elements(split_input);
	return (0);
}