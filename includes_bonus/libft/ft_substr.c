/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:02:58 by isporras          #+#    #+#             */
/*   Updated: 2024/01/29 13:06:58 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
//int main ()
//{
//	char str[] = "hola ke dise";
//	printf("%s", ft_substr(str, 12, 1));
//}
