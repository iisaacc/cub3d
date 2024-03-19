/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:54:07 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 20:03:24 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*obj;
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		obj = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = obj;
	}
	*lst = NULL;
}
