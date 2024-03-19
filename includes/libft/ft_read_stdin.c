/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:52:21 by isporras          #+#    #+#             */
/*   Updated: 2023/11/07 11:52:21 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_stdinput(void)
{
	char	*buffer;
	char	*tmp;
	int		bytesread;

	tmp = ft_strdup("");
	buffer = ft_calloc(BUFSIZE + 1, sizeof(char));
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(0, buffer, BUFSIZE);
		buffer[bytesread] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		free(buffer);
		buffer = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
		if (!buffer)
			return (NULL);
	}
	free(buffer);
	return (tmp);
}
