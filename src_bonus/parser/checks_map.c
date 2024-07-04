/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:14 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 12:31:17 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	ft_spaces_unclosed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' && (map[i][j - 1] == ' '
				|| map[i][j - 1] == '\0'))
				|| (map[i][j] == '0' && (map[i][j + 1] == ' '
				|| map[i][j + 1] == '\0'))
				|| (map[i][j] == '0' && (map[i - 1][j] == ' '
				|| map[i - 1][j] == '\0'))
				|| (map[i][j] == '0' && (map[i + 1][j] == ' '
				|| map[i + 1][j] == '\0')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (ft_spaces_unclosed(map))
		return (ft_error_msg("Map has spaces without closing walls", NULL), 1);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' '))
			j++;
		if (map[i][j] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_error_msg("Map is not surrounded by walls", NULL), 1);
		if (i == 0 || i == ft_count_lines2d(map) - 1)
		{
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (ft_error_msg("Map is not surrounded", NULL), 1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_strange_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][0] == '\0')
			return (ft_error_msg("Empty line in map", NULL), 1);
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != ' ')
				return (ft_error_msg("Strange character : ", &map[i][j]), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double_position(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				count++;
			if (count > 1)
				return (ft_error_msg("Double position in map", NULL), 1);
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
	if (ft_check_double_position(map) == 1)
		return (1);
	return (0);
}
