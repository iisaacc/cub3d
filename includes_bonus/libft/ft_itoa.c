/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:08:35 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 17:38:13 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countn(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	long	num;

	num = n;
	size = countn(num);
	str = (char *)malloc(size + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	i = 0;
	while (num > 9)
	{
		str[size - 1 - i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	str[size - 1 - i] = num + '0';
	str[size] = '\0';
	return (str);
}

//int main()
//{
//	int n = -2147483648;
//	printf("%s\n", ft_itoa(n));
//}
