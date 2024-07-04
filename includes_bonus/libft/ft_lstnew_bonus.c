/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:05:14 by isporras          #+#    #+#             */
/*   Updated: 2023/04/21 16:31:28 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*newobj;

	newobj = (t_list *)malloc(sizeof(struct s_list));
	if (!newobj)
		return (NULL);
	newobj->content = content;
	newobj->next = NULL;
	return (newobj);
}
