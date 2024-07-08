/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:08:56 by isporras          #+#    #+#             */
/*   Updated: 2024/07/08 13:04:07 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

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

int	ft_switch_coord(t_cub *cub, int y, int x)
{
	if (cub->map->map[y][x] == 'N')
		return (0);
	else if (cub->map->map[y][x] == 'E')
		return (1);
	else if (cub->map->map[y][x] == 'S')
		return (2);
	else if (cub->map->map[y][x] == 'W')
		return (3);
	return (ft_error_msg("Invalid character in map", NULL), -1);
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
				cub->player->p_y = y + 0.5;
				cub->player->p_x = x + 0.5;
				return (ft_switch_coord(cub, y, x));
			}
			x++;
		}
		y++;
	}
	return (ft_error_msg("No initial point of view found", NULL), -1);
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
	if (ft_parser_textures(cub) == 1)
		return (ft_delete(cub), 1);
	return (0);
}
