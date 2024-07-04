/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:32:13 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:36:32 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findc(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		i2;
	char	*set2;

	if (!s1 || !set)
		return (NULL);
	set2 = (char *)set;
	i2 = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0' && ft_findc(set2, s1[i]) == 1)
		i++;
	while (i2 > 0 && ft_findc(set2, s1[i2]) == 1)
		i2--;
	return (ft_substr(s1, i, i2 - i + 1));
}

//int main ()
//{
//	char *str1 = " hollllla";
//	char *str2 = "hoa";
//	printf("%s", ft_strtrim(str1, str2));
//}
