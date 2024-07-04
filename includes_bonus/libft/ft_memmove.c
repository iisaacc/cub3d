/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:48:34 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:44:22 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || !len)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *)dst + (len - 1)) = *((char *)src + (len - 1));
			len--;
		}
	}
	return (dst);
}
//int main ()
//{
//	char b[] = "holakdise";
//	char a[] = "hastaluego";

//	ft_memmove(b, a, 5);
//	printf("%s",b);
//	return (0);
//}
