/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:59:08 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/30 17:48:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split)
{
	int	i;

	i = 0;
	if (!split || !*split)
		return ;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
