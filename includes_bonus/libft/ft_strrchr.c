/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:13:48 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:45:29 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	x;

	x = 0;
	i = ft_strlen(s);
	while (i >= 0 && x == 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
			x = 1;
		}
		i--;
	}
	return (NULL);
}

//int main ()
//{
//	char *str1 = "hola";
//	printf("%s", ft_strrchr(str1, '\0'));
//}
