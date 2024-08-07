/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:19:14 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 13:19:21 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_count_lines_fd(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (count);
}

void	ft_cut_char(char **str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				str[i][j] = '\0';
			j++;
		}
		i++;
	}
}

char	**ft_read_and_split(char *file)
{
	char	**array;
	char	*line;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("Error\nInvalid file", NULL), NULL);
	len = ft_count_lines_fd(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	array = ft_calloc((len + 1), sizeof(char *));
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		array[len] = line;
		line = get_next_line(fd);
		len++;
	}
	array[len] = NULL;
	return (array);
}
