/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:03:36 by isporras          #+#    #+#             */
/*   Updated: 2023/11/07 12:03:36 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_fd(int fd)
{
	char	*buffer;
	char	*tmp;
	int		bytesread;

	tmp = ft_strdup("");
	buffer = ft_calloc(BUFSIZE + 1, sizeof(char));
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFSIZE);
		buffer[bytesread] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		free(buffer);
		buffer = ft_calloc(BUFSIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	free(buffer);
	return (tmp);
}
