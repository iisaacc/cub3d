/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:26:01 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 13:20:58 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		ft_error_msg("Single argument specifying a .cub file", NULL);
	else
	{
		if (ft_parser(argv[1], &cub) == 1)
			return (1);
		printf("Running game\n");
		ft_game_loop(&cub);
		printf("Game over\n");
	}
	return (0);
}
