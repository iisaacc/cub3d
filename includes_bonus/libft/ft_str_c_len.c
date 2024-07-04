/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_c_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:38:41 by isporras          #+#    #+#             */
/*   Updated: 2024/02/20 12:38:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cuenta cuantos caracteres hay hasta el caracter c
int	ft_str_c_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
