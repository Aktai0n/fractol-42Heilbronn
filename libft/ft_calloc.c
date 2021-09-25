/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:03:14 by skienzle          #+#    #+#             */
/*   Updated: 2021/08/22 14:23:39 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*memory;
	size_t	tot_size;

	tot_size = nitems * size;
	memory = malloc(tot_size);
	if (!memory)
		return (0);
	ft_memset(memory, 0, tot_size);
	return (memory);
}
