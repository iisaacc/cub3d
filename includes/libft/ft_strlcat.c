/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:37:02 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:43:32 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dstlen;
	unsigned int	i;

	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
//int main()
//{
//    char first[] = "This is ";
//    char last[] = "a potentially long string";
//    //printf("Value returned: %zu\n",ft_strlcat(first, last, 30));
//    printf("Value returned: %zu\n",strlcat(first, last, 8));
//	printf("dest ahora es: %s\n",first);
//    return(0);
//}
