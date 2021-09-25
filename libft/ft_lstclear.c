/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:04:23 by skienzle          #+#    #+#             */
/*   Updated: 2021/08/22 14:24:36 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstdel_rec(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return (0);
	if (lst -> content)
		del(lst -> content);
	ft_lstdel_rec(lst -> next, del);
	free(lst);
	return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst)
		*lst = ft_lstdel_rec(*lst, del);
}
