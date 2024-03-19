/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:23:23 by isporras          #+#    #+#             */
/*   Updated: 2024/01/17 14:24:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpy_2d(char **src)
{
	int		i;
	char	**dst;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
