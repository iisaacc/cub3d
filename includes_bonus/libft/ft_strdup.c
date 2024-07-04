/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:52:09 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:44:53 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1) + 1;
	str = (char *)malloc(size * sizeof(char));
	if (str != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
//int main()
//{
//	char s1[] = "hola";
//	printf("%s", ft_strdup(s1));
//}
