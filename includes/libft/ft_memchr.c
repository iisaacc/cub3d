/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:04:13 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:44:14 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	val;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (i < n)
	{
		if (*ptr == val)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (0);
}
//int main ()
//{
//	char b[] = "holakdise";

//	printf("%s",ft_memchr(b, 'k', 5));
//	return (0);
//}
