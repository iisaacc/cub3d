/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:35 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:45:26 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		i2 = 0;
		while ((haystack[i + i2] == needle[i2]) && (haystack[i + i2] != '\0')
			&& i + i2 < len)
		{
			if (needle[i2 +1] == '\0')
				return ((char *)haystack + i);
			i2++;
		}
		i++;
	}
	return (0);
}

//int main ()
//{
//	char *str1 = "hola";
//	char *str2 = "dsfvhola dsghoasdfsdffghjklñ";
//	printf("%s", ft_strnstr(str2, str1, 6));
//}
