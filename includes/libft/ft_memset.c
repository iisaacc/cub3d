/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:25:35 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:44:24 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	ptr = b;
	val = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = val;
		i++;
	}
	b = ptr;
	return (b);
}
//int main ()
//{
//	char b[10];
//	char *c;
//	int i = 0;

//	c = ft_memset(b, 0, 0);

//	while (i < 10)
//	{
//		printf("%i",c[i]);
//		i++;
//	}
//	return (0);
//}
