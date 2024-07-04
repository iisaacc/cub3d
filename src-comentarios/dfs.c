/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:29 by isporras          #+#    #+#             */
/*   Updated: 2024/03/06 13:07:29 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_dfs(char **mapcopy, int x, int y)
{
	int	i;
	int	xi[4];
	int	yi[4];

	xi[0] = 0;
	xi[1] = 1;
	xi[2] = 0;
	xi[3] = -1;
	yi[0] = -1;
	yi[1] = 0;
	yi[2] = 1;
	yi[3] = 0;
	if (mapcopy[y][x] == '1' || mapcopy[y][x] == 'V')
		return ;
	else
		mapcopy[y][x] = 'V';
	i = 0;
	while (i < 4)
	{
		ft_dfs(mapcopy, x + xi[i], y + yi[i]);
		i++;
	}
}

//Busco la primera posición válida para empezar el dfs.
void	ft_valid_pos(char **mapcopy, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (mapcopy[i])
	{
		j = 0;
		while (mapcopy[i][j])
		{
			if (mapcopy[i][j] == '0')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_parse_dfs(char **map)
{
	int	i;
	int	j;

	i = 0;
	printf("map: \n");
	ft_print_split(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != 'V' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != ' ')
				|| (map[i][j] == 'V' && map[i][j + 1] == ' ')
				|| (map[i][j] == 'V' && map[i][j - 1] == ' '))
			{
				printf("map[%d][%d]: %c\n", i, j, map[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_way(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_valid_pos(map, &x, &y);
	ft_dfs(map, x, y);
	return (ft_parse_dfs(map));
}