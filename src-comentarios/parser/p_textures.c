#include "../../includes/cub3d.h"

void	ft_fill_rgb(uint8_t *rgb, char *str)
{
	char	**split_num;

	split_num = ft_split(str, ',');
	rgb[0] = (uint8_t)ft_atoi(split_num[0]);
	rgb[1] = (uint8_t)ft_atoi(split_num[1]);
	rgb[2] = (uint8_t)ft_atoi(split_num[2]);
	ft_free_2d(split_num);
}

//Elimina los saltos de línea de las rutas de las texturas
void	ft_remove_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}
void	ft_get_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->split_input[i])
	{
		if (ft_strncmp(cub->split_input[i], "NO ", 3) == 0)
			cub->tx->no_pth = ft_strdup(&cub->split_input[i][3]);
		else if (ft_strncmp(cub->split_input[i], "SO ", 3) == 0)
			cub->tx->so_pth = ft_strdup(&cub->split_input[i][3]);
		else if (ft_strncmp(cub->split_input[i], "WE ", 3) == 0)
			cub->tx->we_pth = ft_strdup(&cub->split_input[i][3]);
		else if (ft_strncmp(cub->split_input[i], "EA ", 3) == 0)
			cub->tx->ea_pth = ft_strdup(&cub->split_input[i][3]);
		else if (ft_strncmp(cub->split_input[i], "F ", 2) == 0)
			ft_fill_rgb(cub->tx->f_rgb, &cub->split_input[i][2]);
		else if (ft_strncmp(cub->split_input[i], "C ", 2) == 0)
			ft_fill_rgb(cub->tx->c_rgb, &cub->split_input[i][2]); 
		i++;
	}
	ft_remove_endl(cub->tx->no_pth);
	ft_remove_endl(cub->tx->so_pth);
	ft_remove_endl(cub->tx->we_pth);
	ft_remove_endl(cub->tx->ea_pth);
}

void	ft_init_tx_struct(t_cub *cub)
{
	cub->tx->no_pth = NULL;
	cub->tx->so_pth = NULL;
	cub->tx->we_pth = NULL;
	cub->tx->ea_pth = NULL;
	cub->tx->f_rgb[0] = -1;
	cub->tx->f_rgb[1] = -1;
	cub->tx->f_rgb[2] = -1;
	cub->tx->c_rgb[0] = -1;
	cub->tx->c_rgb[1] = -1;
	cub->tx->c_rgb[2] = -1;
}


int	ft_parser_textures(t_cub *cub)
{
	ft_init_tx_struct(cub);
	ft_get_textures(cub);
	return (0);
}