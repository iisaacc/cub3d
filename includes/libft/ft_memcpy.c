/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:11:41 by isporras          #+#    #+#             */
/*   Updated: 2024/01/29 11:46:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
//int main ()
//{
//	int b[] = {1,1,1,1,1};
//	int a[] = {2,2,2,2,2};

//	memcpy(b, a, 2);
//	printf("%i",b[0]);
//	return (0);
//}
