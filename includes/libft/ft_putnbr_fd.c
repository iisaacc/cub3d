/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:21:04 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 16:32:08 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	num = n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	c = '0' + num % 10;
	write(fd, &c, 1);
}
