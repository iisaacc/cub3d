/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:08:14 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 13:29:18 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	ft_fill_rgb(uint8_t *rgb, char *str)
{
	char	**split_num;
	int		i;

	split_num = ft_split(str, ',');
	if (!split_num)
		return (ft_error_msg("No rgb code", NULL), 1);
	i = 0;
	while (split_num[i])
	{
		rgb[i] = (uint8_t)ft_atoi(split_num[i]);
		i++;
	}
	ft_free_2d(split_num);
	if (i != 3)
		return (ft_error_msg("No rgb code", NULL), 1);
	return (0);
}

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

int	ft_get_textures(t_cub *cub)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
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
			h += ft_fill_rgb(cub->tx->f_rgb, &cub->split_input[i][2]);
		else if (ft_strncmp(cub->split_input[i], "C ", 2) == 0)
			h += ft_fill_rgb(cub->tx->c_rgb, &cub->split_input[i][2]);
		i++;
	}
	if (h != 0)
		return (1);
	return (0);
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
	if (ft_get_textures(cub) == 1)
		return (1);
	ft_remove_endl(cub->tx->no_pth);
	ft_remove_endl(cub->tx->so_pth);
	ft_remove_endl(cub->tx->we_pth);
	ft_remove_endl(cub->tx->ea_pth);
	return (0);
}
