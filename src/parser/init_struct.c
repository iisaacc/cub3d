/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:17:55 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 13:17:55 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_struct(t_cub *cub)
{
	cub->tx = ft_calloc(1, sizeof(t_tx));
	cub->player = ft_calloc(1, sizeof(t_player));
	cub->ray = ft_calloc(1, sizeof(t_ray));
	cub->wall = ft_calloc(1, sizeof(t_wall));
	cub->map = ft_calloc(1, sizeof(t_map));
	cub->ray->img = NULL;
	cub->ray->angle = 0;
	cub->player->p_x = 0;
	cub->player->p_y = 0;
	cub->player->p_a = 0;
	cub->player->initial_pov = 0;
	cub->map->map = NULL;
	cub->split_input = NULL;
	cub->arrow = NULL;
}
