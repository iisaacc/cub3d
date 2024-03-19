/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:17:14 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 20:05:22 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*obj;
	t_list	*aux;

	if (!lst)
		return (NULL);
	obj = 0;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!aux)
		{
			ft_lstclear(&obj, del);
			return (NULL);
		}
		ft_lstadd_back(&obj, aux);
		lst = lst->next;
	}
	return (obj);
}
