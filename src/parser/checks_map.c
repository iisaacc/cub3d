/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:14 by isporras          #+#    #+#             */
/*   Updated: 2024/03/07 11:43:14 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_spaces_unclosed(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j])
		{
			if ((split_input[i][j] == '0' && split_input[i][j - 1] == ' ')
				|| (split_input[i][j] == '0' && split_input[i][j + 1] == ' ')
				|| (split_input[i][j] == '0' && split_input[i - 1][j] == ' ')
				|| (split_input[i][j] == '0' && split_input[i + 1][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_walls(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	if (ft_spaces_unclosed(split_input)) //Chequea si hay espacios por dentro del mapa sin paredes que los cierren
		return (ft_error_msg("Map has spaces without closing walls", NULL), 1);
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j] && (split_input[i][j] == ' '))
			j++;
		if (split_input[i][j] != '1' || split_input[i][ft_strlen(split_input[i]) - 1] != '1')
			return (ft_error_msg("Map is not surrounded by walls", NULL), 1);
		if (i == 0 || i == ft_count_lines2d(split_input) - 1)
		{
			while (split_input[i][j])
			{
				if (split_input[i][j] != '1' && split_input[i][j] != ' ')
					return (ft_error_msg("Map is not surrounded by walls", NULL), 1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_strange_chars(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		if (split_input[i][0] == '\0')
			return (ft_error_msg("Empty line in map", NULL), 1);
		while (split_input[i][j])
		{
			if (split_input[i][j] != '0' && split_input[i][j] != '1'
				&& split_input[i][j] != 'N' && split_input[i][j] != 'S'
				&& split_input[i][j] != 'W' && split_input[i][j] != 'E'
				&& split_input[i][j] != ' ')
				return (ft_error_msg("Strange character in map: ", &split_input[i][j]), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_map_checks(char **map)
{
	if (ft_strange_chars(map) == 1)
		return (1);
	if (ft_check_walls(map) == 1)
		return (1);
	return (0);
}