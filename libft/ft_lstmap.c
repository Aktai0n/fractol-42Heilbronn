/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:04:43 by skienzle          #+#    #+#             */
/*   Updated: 2021/08/23 10:44:11 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;

	if (!lst || !f)
		return (0);
	new_node = ft_lstnew(f(lst -> content));
	if (!new_node)
		return (0);
	if (!(new_node -> content))
	{
		ft_lstdelone(new_node, del);
		return (0);
	}
	if (!(lst -> next))
		new_node -> next = 0;
	else
	{
		new_node -> next = ft_lstmap(lst -> next, f, del);
		if (!(new_node -> next))
		{
			ft_lstdelone(new_node, del);
			return (0);
		}
	}
	return (new_node);
}
