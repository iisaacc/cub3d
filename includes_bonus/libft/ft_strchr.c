/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:01:51 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:44:40 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (*s == '\0' && c == 0)
		return ((char *)s);
	while (*s)
	{
		if (s[i] == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
//int main()
//{
//	char hola[] = "";
//	printf("%s",ft_strchr(hola, '\0'));
//	printf("%s",ft_strchr(hola, '\0'));
//}
