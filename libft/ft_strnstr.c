/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:06:16 by skienzle          #+#    #+#             */
/*   Updated: 2021/08/18 17:32:26 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str2[0])
		return ((char *)str1);
	i = 0;
	while (str1[i])
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			while (str1[i + j] == str2[j] && (i + j) < n && str1[i + j])
			{
				if (str2[j + 1] == '\0')
					return ((char *)str1 + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
