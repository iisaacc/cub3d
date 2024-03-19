/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:10:28 by isporras          #+#    #+#             */
/*   Updated: 2023/10/19 12:47:33 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countl(char const *s, char c)
{
	int	i;
	int	b;
	int	n;

	n = 0;
	b = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			b = 0;
		if (s[i] != c && b == 0)
		{
			n++;
			b = 1;
		}
		i++;
	}
	return (n);
}

int	ft_to2d(char const *s, int len, char **ans, int lap)
{
	int	i;

	ans[lap] = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!ans[lap])
	{
		while (lap > 0)
		{
			free(ans[lap - 1]);
			lap--;
		}
		free(ans);
		return (1);
	}
	while (i < len)
	{
		ans[lap][i] = s[i];
		i++;
	}
	ans[lap][i] = '\0';
	return (0);
}

char	**ft_splitaux(char **ans, char *s, char c)
{
	int	i;
	int	len;
	int	lap;

	lap = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		if (len > 0)
		{
			if (ft_to2d(&s[i], len, ans, lap) == 1)
				return (NULL);
			lap++;
			i += len;
		}
	}
	ans[ft_countl(s, c)] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;

	ans = (char **)malloc((ft_countl(s, c) + 1) * sizeof(char *));
	if (!ans)
		return (NULL);
	return (ft_splitaux(ans, (char *)s, c));
}
//int main()
//{
//	char str1[] = "hola tu hola gola ";
//	printf("%i\n", ft_countl(str1, ' '));
//	char **ans = ft_split(str1, ' ');
//	int i  = 0;
//	while (ans[i])
//	{
//		printf("%s\n", ans[i]);
//		i++;
//	}
//}
